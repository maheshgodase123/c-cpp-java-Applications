#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<iostream>
#include<io.h>


#define MAXINODE 50     // this is max file count we can create(50 file fkt apan create kru shakto)

#define READ 1      // permission on file to perform
#define WRITE 2

#define MAXFILESIZE 2048   

#define REGULAR 1       // this are file types regular and special
#define SPECIAL 2 

#define START 0     // use for lseek function 
#define CURRENT 1   // mnje kuthun start krnare apan file read karnyasathi
#define END 2       


typedef struct superblock
{
    int TotalInodes;
    int FreeInode;
}SUPERBLOCK,*PSUPERBLOCK;

typedef struct inode
{
    char FileName[50];
    int InodeNumber;
    int FileSize;
    int FileActualSize;
    int FileType;
    char *Buffer;           // ani ha file kuthlya block madhe save ahe(DB madhe) tyala point krtoy(ufdt->filetable->buffer)
    int LinkCount;          // count of link which can access this inode(mnje apan windows madhe shortcuts create krto tasa)(it is remain same whole program which is 1)
    int ReferenceCount;     // how many references are refereing to that inode(mnje sir lecture ghetayet 350 bghnare ahet trr reference count 350 ani 50 baher kadhale mg rcnt = 300)
    int permission;         //1     2      3
    struct inode *next;
}INODE,*PINODE,**PPINODE;

typedef struct filetable
{
    int readoffset;
    int writeoffset;
    int count;                      // it will remain 1 only whole program(increase if child process is created and that is not happening in program)
    int mode;   //1 2 3
    PINODE ptrinode;                // line(29(36))ha inode la point krtoy(buffer la)
}FILETABLE,*PFILETABLE;

typedef struct ufdt  // it is not ideal to create structure for only on datafield as structure is used to create group of heterogenious datatypes(but it is used bcoz os contains the ufdt struct in it for that implementation purpose we alse created ufdt stuct) feel yenyasathi
{
    PFILETABLE ptrfiletable;        // line(43(49))filetable la point krtoy(diagram madhe dilay book madhe)
    // PFILETABLE *filetable;
}UFDT;

//typedef struct ufdt UFDT;
// gloabal variables

UFDT UFDTArr[MAXINODE]; // ha diagram madhla ufdt cha array(pointers cha array ahe je filetable la point krtat)
SUPERBLOCK SUPERBLOCKobj;
PINODE head = NULL;     // yamadhe aplya dilb chya ll cha address asnare

void man(char *name)
{
    if(name == NULL)
    {
        return ;
    }

    if(strcmp(name,"create") == 0)
    {
        printf("Description : Used To Create New Regular File\n");
        printf("Usage : create File_Name Permission\n");
    }
    else if(strcmp(name,"read") == 0)
    {
        printf("Description : Used To Read Data From Regular file\n");
        printf("Usage : read File_name No_Of_Bytes_To_Read\n");
    }
    else if(strcmp(name,"write") == 0)
    {
        printf("Description : Used To Write Into File\n");
        printf("Usage : write File_name\n After This Enter The Data You Want To Write\n");
    }
    else if(strcmp(name,"ls") == 0)
    {
        printf("Description : Used To list All Information file\n");
        printf("Usage : ls\n");
    }
    else if(strcmp(name,"stat") == 0)
    {
        printf("Description : Used To Dispay Information of File\n");
        printf("Usage : stat File_name\n");
    }
    else if(strcmp(name,"fstat") == 0)
    {
        printf("Description : Used To Dispay Information of File\n");
        printf("Usage : fstat File_Descriptor\n");
    }
    else if(strcmp(name,"truncate") == 0)
    {
        printf("Description : Used To Remove Data From File\n");
        printf("Usage : truncate File_name\n");
    }
    else if(strcmp(name,"open") == 0)
    {
        printf("Description : Used To Ope Existing File\n");
        printf("Usage : open File_name mode\n");
    }
    else if(strcmp(name,"close") == 0)
    {
        printf("Description : Used To Closed Opened File\n");
        printf("Usage : close File_name\n");
    }
    else if(strcmp(name,"closeall") == 0)
    {
        printf("Description : Used To Closed All Opened File\n");
        printf("Usage : closeall\n");
    }
    else if(strcmp(name,"lseek") == 0)
    {
        printf("Description : Used To Change File Offset\n");
        printf("Usage : lssek File_name ChangeInOffset StartPoint\n");
    }
    else if(strcmp(name,"rm") == 0)
    {
        printf("Description : Used To Delete The File\n");
        printf("Usage : rm File_name\n");
    }
    else
    {
        printf("ERROR : No Manual Entry Available\n");
    }
}

void DisplayHelp()
{
    printf("ls : To List Out All File\n");
    printf("clear : To Clear The Console\n");
    printf("create : Use To Create New Regular File\n");
    printf("open : To Open The File\n");
    printf("close : To Close The File\n");
    printf("closeall : To Close All Opened Files\n");
    printf("read : To Read The Contents From The File\n");
    printf("write : To Write The Contents Into File\n");
    printf("exit : To Terminate File System\n");
    printf("stat : To Display Information Of File Using Name\n");
    printf("fstat : To Display Information Of File Using File Descriptor\n");
    printf("lseek : To Seek In The File From Given Point\n");
    printf("truncate : To Remove All The Data From File\n");
    printf("rm : To Delete The File\n");
}

int GetFDFromName(char *name)
{
    int i = 0;

    while(i < MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable != NULL)
        {
            if(strcmp((UFDTArr[i].ptrfiletable->ptrinode->FileName),name) == 0) // compare the filename of every inode with given returns i(fd) if found
            {
                break;
            }
        }
        i++;
    }

    if(i == MAXINODE)   // if name not found i = last value of inode
    {
        return -1;
    }
    else
    {
        return i;
    }
}

PINODE Get_Inode(char *name)
{
    PINODE temp = head;
    int i = 0;

    if(name == NULL)
    {
        return NULL;
    }

    while(temp != NULL)
    {
        if(strcmp(name,temp->FileName)== 0)   
        {
            break;
        }
        temp = temp->next;
    }

    return temp;
}

void CreateDILB()
{
    int i = 1;
    PINODE newn = NULL;
    PINODE temp = head;

    while(i <= MAXINODE)
    {
        newn = (PINODE)malloc(sizeof(INODE));// nodes sathi memory allocate zali(each node of size 94 bytes)

        // INITIALIZING ALL FIELDS
        newn->LinkCount = 0;
        newn->ReferenceCount = 0;
        newn->FileType = 0;
        newn->FileSize = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        newn->InodeNumber = i;

        if(temp == NULL)
        {
            head = newn;
            temp = head;
        }
        else
        {
            temp->next = newn;
            temp = temp->next;
        }
        i++;
    }
    printf("DILB created Successfully\n");
}

void InitialiseSuperBlock()
{
    int i = 0;
    while(i < MAXINODE) // ha ufdt chya array la null ne initialize kela garbage deu nahi mhanun
    {
        UFDTArr[i].ptrfiletable = NULL;
        i++;
    }

    SUPERBLOCKobj.TotalInodes = MAXINODE;
    SUPERBLOCKobj.FreeInode = MAXINODE;
}

int CreateFile(char *name, int permission)
{
    int i = 0;
    PINODE temp = head;

    if((name == NULL) || (permission == 0) || (permission > 3))
    {
        return -1;
    }
    if(SUPERBLOCKobj.FreeInode == 0)
    {
        return -2;
    }
 
    if(Get_Inode(name) != NULL)
    {
        return -3;
    }

    (SUPERBLOCKobj.FreeInode)--;


    while(temp != NULL)
    {
        //if(temp->FileType == 0)
        if(temp->LinkCount == 0)    // bcoz we are setting linkcount = 0 and filtype = 0 after deleting it
        // so we can reuse here
        {
            break;
        }

        temp= temp->next;
    }

    while(i < 50)
    {
        if(UFDTArr[i].ptrfiletable == NULL)
        {
            break;
        }
        i++;
    }

    UFDTArr[i].ptrfiletable = (PFILETABLE)malloc(sizeof(FILETABLE));

    UFDTArr[i].ptrfiletable->count = 1;
    UFDTArr[i].ptrfiletable->mode = permission;
    UFDTArr[i].ptrfiletable->readoffset = 0;
    UFDTArr[i].ptrfiletable->writeoffset = 0;

    UFDTArr[i].ptrfiletable->ptrinode = temp;

    strcpy(UFDTArr[i].ptrfiletable->ptrinode->FileName,name);
    UFDTArr[i].ptrfiletable->ptrinode->FileType = REGULAR;
    UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount = 1;
    UFDTArr[i].ptrfiletable->ptrinode->LinkCount = 1;
    UFDTArr[i].ptrfiletable->ptrinode->FileSize = MAXFILESIZE;
    UFDTArr[i].ptrfiletable->ptrinode->FileActualSize = 0;
    UFDTArr[i].ptrfiletable->ptrinode->permission = permission;
    UFDTArr[i].ptrfiletable->ptrinode->Buffer = (char *)malloc(MAXFILESIZE);

    return i;
}

// rm_File("Demo.txt")

int rm_File(char *name)
{
    int fd = 0;

    fd = GetFDFromName(name);

    if(fd == -1)
    {
        return -1;
    }

    (UFDTArr[fd].ptrfiletable->ptrinode->LinkCount)--;

    if(UFDTArr[fd].ptrfiletable->ptrinode->LinkCount == 0)
    {
        UFDTArr[fd] .ptrfiletable->ptrinode->FileType = 0;
        // free(UFDTArr[fd].ptrfiletable->ptrinode->Buffer);
        free(UFDTArr[fd].ptrfiletable);
    }
    
    UFDTArr[fd].ptrfiletable = NULL;
    (SUPERBLOCKobj.FreeInode)++;

    return 0;
}

int ReadFile(int fd, char *arr, int isize)
{
    int read_size = 0;

    if(UFDTArr[fd].ptrfiletable == NULL)    return -1;

    if(UFDTArr[fd].ptrfiletable->mode != READ && UFDTArr[fd].ptrfiletable->mode != READ+WRITE)
    {
        return -2;
    }

    if(UFDTArr[fd].ptrfiletable->ptrinode->permission != READ && UFDTArr[fd].ptrfiletable->ptrinode->permission != READ+WRITE)
    {
        return -2;
    }

    if(UFDTArr[fd].ptrfiletable->readoffset == UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize)
    {
        return -3;
    }

    if(UFDTArr[fd].ptrfiletable->ptrinode->FileType != REGULAR)
    {
        return -4;
    }

    read_size = (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) - (UFDTArr[fd].ptrfiletable->readoffset);  // ha kity bytes urlyat read karaychya te return krto mnje (actual size of that file - adhi kity read krun zalay(offset))example(10 bytes - 5 bytes)

    if(read_size < isize)   // jrr size diliye tevdha data nsel read karayla trr ahe tevdha read kra
    {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->readoffset),read_size);   // call krtana apan array pass krto so read kelele tyat takaycha(ex - arr)
        UFDTArr[fd].ptrfiletable->readoffset = UFDTArr[fd].ptrfiletable->readoffset + read_size;
    }
    else    // data present ahe tevdha read kara
    {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->readoffset),isize);
        (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->readoffset) + isize;
    }

    return isize;
}

int WriteFile(int fd, char *arr, int isize)
{
    if(((UFDTArr[fd].ptrfiletable->mode) != WRITE) && ((UFDTArr[fd].ptrfiletable->mode) != READ+WRITE))
    {
        return -1;
    }

    if(((UFDTArr[fd].ptrfiletable->ptrinode->permission)!= WRITE) && ((UFDTArr[fd].ptrfiletable->ptrinode->permission) != READ+WRITE))
    {
        return -1;
    }

    if((UFDTArr[fd].ptrfiletable->writeoffset) == MAXFILESIZE)
    {
        return -2;      // this type of return is known as error code
    }

    if(((UFDTArr[fd].ptrfiletable->writeoffset)+ isize) > MAXFILESIZE)
    {
        return -3;
    }
    if((UFDTArr[fd].ptrfiletable->ptrinode->FileType) != REGULAR)
    {
        return -3;
    }

    strncpy((UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->writeoffset),arr,isize);      // file madhe write(copy) kela writeoffset chya pudhun
    //                                                   1                                           2     3 
    //strncpy(1000+5(address of buffer + kity adhi data lihila hota tyacha address),kay lihaycha, kity lihaycha)

    (UFDTArr[fd].ptrfiletable->writeoffset) = (UFDTArr[fd].ptrfiletable->writeoffset) + isize;          // writeoffset update kela

    (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) = (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + isize;    // actualfilesize wadhvli

    return isize;   // size return kela data kity write kela 
}

int OpenFile(char *name, int mode)
{
    int i=0;
    PINODE temp = NULL;

    if(name == NULL || mode <= 0)
    {
        return -1;
    }

    temp  = Get_Inode(name);
    if(temp == NULL)
    {
        return -2;
    }

    if(temp->permission<mode)
    {
        return -3;
    }

    while(i<50)
    {
        if(UFDTArr[i].ptrfiletable == NULL)
        {
            break;
        }
        i++; 
    }

    UFDTArr[i].ptrfiletable = (PFILETABLE)malloc(sizeof(FILETABLE));
    if(UFDTArr[i].ptrfiletable == NULL)
    {
        return -1;
    }
    UFDTArr[i].ptrfiletable->count = 1;
    UFDTArr[i].ptrfiletable->mode = mode;

    if(mode == READ+WRITE)
    {
        UFDTArr[i].ptrfiletable->readoffset = 0;
        UFDTArr[i].ptrfiletable->writeoffset = 0;
    }
    else if(mode == READ)
    {
        UFDTArr[i].ptrfiletable->readoffset = 0;
    }
    else if(mode == WRITE)
    {
        UFDTArr[i].ptrfiletable->writeoffset = 0;
    }

    UFDTArr[i].ptrfiletable->ptrinode = temp;
    (UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount)++;

    return i;

}

void CloseFileByName(int fd)
{
        UFDTArr[fd].ptrfiletable->readoffset = 0;
        UFDTArr[fd].ptrfiletable->writeoffset = 0;
        (UFDTArr[fd].ptrfiletable->ptrinode->ReferenceCount)--;
}
    
int CloseFileByName(char *name)
{
    int i=0;
    i = GetFDFromName(name);

    if(i == -1)
    {
        return -1;
    }

    UFDTArr[i].ptrfiletable->readoffset = 0;
    UFDTArr[i].ptrfiletable->writeoffset = 0;
    (UFDTArr->ptrfiletable->ptrinode->ReferenceCount)--;

    return 0;
}

void CloseAllFile()
{
    int i = 0;
    while(i < 50)
    {
        if(UFDTArr[i].ptrfiletable != NULL)
        {
            UFDTArr[i].ptrfiletable->readoffset = 0;
            UFDTArr[i].ptrfiletable->writeoffset = 0;
            (UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount)--;
            break;
        }
        i++;
    }
}

int LseekFile(int fd, int size, int from)
{
    if((fd < 0) || (from > 2))
    {
        return -1;
    }

    if(UFDTArr[fd].ptrfiletable == NULL)
    {
        return -1;
    }

    if((UFDTArr[fd].ptrfiletable->mode == READ) || (UFDTArr[fd].ptrfiletable->mode == READ+WRITE))
    {
        if(from == CURRENT)
        {
            if(((UFDTArr[fd].ptrfiletable->readoffset)+ size) > (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize))
            {
                return -1;
            }

            if(((UFDTArr[fd].ptrfiletable->readoffset)+ size) < 0)
            {
                return -1;
            }

            (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->readoffset) + size;

        }

        else if(from == START)
        {
              if(size > (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize)) 
              {
                return -1;
              }

              else if(size < 0)
              {
                return -1;
              }

              (UFDTArr[fd].ptrfiletable->readoffset) = size; 
        }

        else if(from == END)
        {
            if((UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + size > MAXFILESIZE)
            {
                return -1;
            }

            if(((UFDTArr[fd].ptrfiletable->readoffset) + size) < 0)
            {
                return -1;
            }

            (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + size;
        }
    }

    else if(UFDTArr[fd].ptrfiletable->mode == WRITE || (UFDTArr[fd].ptrfiletable->mode == READ+WRITE))
    {
        if(from == CURRENT)
        {
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) > MAXFILESIZE)
            {
                return -1;
            }
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) < 0)
            {
                return -1;
            }

            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) > (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize))
            {
                (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) = (UFDTArr[fd].ptrfiletable->writeoffset) + size;
            }

            (UFDTArr[fd].ptrfiletable->writeoffset) = (UFDTArr[fd].ptrfiletable->writeoffset) + size;
        }

        else if(from == START)
        {
            if(size > MAXFILESIZE)
            {
                return -1;
            }
            if(size < 0)
            {
                return -1;
            }

            if(size > (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize))
            {
                (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) = size;
            }

            (UFDTArr[fd].ptrfiletable->writeoffset) = size;
        }
        else if(from == END)
        {
            if((UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + size > MAXFILESIZE)
            {
                return -1;
            }

            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) < 0)
            {
                return -1;
            }

            (UFDTArr[fd].ptrfiletable->writeoffset) = (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + size;
        }
    }

    return 0;
}

void ls_file()
{
    int i = 0;
    PINODE temp = head;

    if(SUPERBLOCKobj.FreeInode == MAXINODE)
    {
        printf("Error : There are no files\n");
        return;
    }

    printf("\nFile Name\tInode Number\tFile Size\tLink Count\n");
    printf("---------------------------------------------------\n");

    while(temp != NULL)
    {
        if(temp->FileType != 0)
        {
            printf("%s\t\t%d\t\t%d\t\t%d\n", temp->FileName, temp->InodeNumber, temp->FileActualSize, temp->LinkCount);
        }

        temp = temp->next;
    }

    printf("----------------------------------------------------\n");
}

int fstat_file(int fd)
{
    PINODE temp = head;
    int i = 0;

    if(fd < 0)
    {
        return -1;
    }

    if(UFDTArr[fd].ptrfiletable == NULL)
    {
        return -2;
    }
 
    temp = UFDTArr[fd].ptrfiletable->ptrinode;

    printf("\n---------------Statistical Information About File---------------\n");
    printf("File name : %s\n",temp->FileName);
    printf("Inode Number %d\n",temp->InodeNumber);
    printf("File Size : %d\n", temp->FileSize);
    printf("Actual File Size : %d\n",temp->FileActualSize);
    printf("Link Count : %d\n",temp->LinkCount);
    printf("Reference Count : %d\n", temp->ReferenceCount);

    if(temp->permission == 1)
    {
        printf("File Permission : Read Only\n");
    }
    else if(temp->permission == 2)
    {
        printf("File Permission : Write\n");
    }
    else if(temp->permission == 3)
    {
        printf("File Permission : Read & Write\n");
    }

    printf("-----------------------------------------------------------------\n\n");

    return 0;
}

int stat_file(char *name)
{
    PINODE temp = head;
    int i = 0;

    if(name == NULL)
    {
        return -1;
    }

    while(temp != NULL)
    {
        if(strcmp(name,temp->FileName) == 0)
        {
            break;
        }

        temp= temp->next;
    }

    if(temp == NULL)
    {
        return -2;
    }

    printf("\n---------------Statistical Information About File---------------\n");
    printf("File name : %s\n",temp->FileName);
    printf("Inode Number %d\n",temp->InodeNumber);
    printf("File Size : %d\n", temp->FileSize);
    printf("ActualFileSize : %d\n",temp->FileActualSize);
    printf("Link Count : %d\n",temp->LinkCount);
    printf("Reference Count : %d\n", temp->ReferenceCount);

    if(temp->permission == 1)
    {
        printf("File Permission : Read Only\n");
    }
    else if(temp->permission == 2)
    {
        printf("File Permission : Write\n");
    }
    else if(temp->permission == 3)
    {
        printf("File Permission : Read & Write\n");
    }

    printf("-----------------------------------------------------------------\n\n");

    return 0;
}

int truncate_File(char *name)
{
    int fd = GetFDFromName(name);

    if(fd == -1)
    {
        return -1;
    }

    memset(UFDTArr[fd].ptrfiletable->ptrinode->Buffer,0,2024); //memset() is used to fill a block of memory with a particular value.
    //memset(starting address of memory to filled, value to be filled, no of bytes to be filled from start(in our case buffer(0)))
    // mnje ak prakare sagla data 0 ne replace kela
    UFDTArr[fd].ptrfiletable->readoffset = 0;
    UFDTArr[fd].ptrfiletable->writeoffset = 0;
    UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize = 0;

    return 0;
}

int main()  // 586
{
    char *ptr = NULL;
    int ret = 0, fd = 0, count = 0;
    char command[4][80], str[80], arr[1024];    // 80 bcoz width of terminal that can fit 80 letteres 

    InitialiseSuperBlock();
    CreateDILB();

    while(1)
    {
        fflush(stdin);
        strcpy(str,"");

        printf("\nCustomize VFS : > ");

        fgets(str,80,stdin);    // scanf("%[^'\n']s", str);

        count = sscanf(str, "%s %s %s %s", command[0],command[1],command[2], command[3]);
        
        if(count == 1)
        {
            if(strcmp(command[0], "ls") == 0)
            {
                ls_file();
            }
            else if(strcmp(command[0], "closeall") == 0)
            {
                CloseAllFile();
                printf("All files closed successfully\n");
                continue;
            }
            else if(strcmp(command[0], "clear") == 0)
            {
                system("cls");
                continue;
            }
            else if(strcmp(command[0], "help") == 0)
            {
                DisplayHelp();
                continue;
            }
            else if(strcmp(command[0], "exit") == 0)
            {
                printf("Terminating the Customised Virtual File System\n");
                break;
            }
            else
            {
                printf("\nERROR : Command not Found !!!\n");
                continue;
            }
        }

        else if(count == 2)
        {
            if(strcmp(command[0], "stat") == 0)
            {
                ret = stat_file(command[1]);

                if(ret == -1)
                {
                    printf("ERROR : Incorrect Parameters\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : There is No Such File\n");
                }

                continue;
            }
            else if(strcmp(command[0], "fstat") == 0)
            {
                ret = fstat_file(atoi(command[1])); //(atoi - alphabet to integers)

                if(ret == -1)
                {
                    printf("ERROR : Incorrect Parameters\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : There is No Such File\n");
                }

                continue;
            }
            else if(strcmp(command[0], "close") == 0)
            {
                ret = CloseFileByName(command[1]);
                if(ret == -1)
                {
                    printf("ERROR : There is no such file\n");
                }
                continue;
            }
            else if(strcmp(command[0], "rm") == 0)
            {
                ret = rm_File(command[1]);
                if(ret == -1)
                {
                    printf("ERROR : There is no such file\n");
                }
                continue;
            }
            else if(strcmp(command[0], "man") == 0)
            {
                man(command[1]);
               
            }
            else if(strcmp(command[0], "write") == 0)
            {
                fd = GetFDFromName(command[1]);
                if(fd == -1)
                {
                    printf("ERROR : Incorrect parameter\n");
                    continue;
                }

                printf("Enter The Data : \n");
                scanf("%[^\n]", arr);

                ret = strlen(arr);
                if(ret == 0)
                {
                    printf("ERROR : Incorrect parameter\n");
                    continue;
                }

                ret = WriteFile(fd,arr,ret);

                if(ret == -1)
                {
                    printf("ERROR : Permission denied\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : There Is No Sufficient Memory To Write\n");
                }
                if(ret == -3)
                {
                    printf("ERROR : It is Not Regular File\n");
                }
                
            }
            else if(strcmp(command[0], "truncate") == 0)
            {
                ret = truncate_File(command[1]);

                if(ret == -1)
                {
                    printf("ERROR : Incorrect parameter\n");
                }
            }
            else
            {
                printf("\nERROR : Command not found!!!\n");
                continue;
            }
        }
        else if(count == 3)
        {
            if(strcmp(command[0],"create") == 0)
            {
                ret = CreateFile(command[1],atoi(command[2]));

                if(ret >= 0)
                {
                    printf("File is successfully created with file descriptor : %d\n", ret);
                }
                if(ret == -1)
                {
                    printf("ERROR : Incorrect parameters\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : There is no inodes\n");
                }
                if(ret == -3)
                {
                    printf("ERROR : File already exists\n");
                }
                if(ret == -4)
                {
                    printf("ERROR : Memory allocation failure\n");
                }

                continue;
            }

            else if(strcmp(command[0],"open") == 0)
            {
                ret = OpenFile(command[1],atoi(command[2]));

                if(ret >= 0)
                {
                    printf("File is successfully opened with file descriptor : %d\n", ret);
                }
                if(ret == -1)
                {
                    printf("ERROR : Incorrect parameters\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : File not present\n");
                }
                if(ret == -3)
                {
                    printf("ERROR : Permission denied\n");
                }
                continue;
            }
            else if(strcmp(command[0], "read") == 0)
            {
                fd = GetFDFromName(command[1]);
                if(fd == -1)
                {
                    printf("ERROR : Incorrect parameter\n");
                    continue;
                }
                ptr = (char *)malloc(sizeof(atoi(command[2]))+1);
                // if command[2] = 0 then minimum we can pass 1 thats why +1

                if(ptr == NULL)
                {
                    printf("ERROR : Memory allocation failure\n");
                    continue;
                }

                ret = ReadFile(fd,ptr,atoi(command[2]));

                if(ret == -1)
                {
                    printf("ERROR : File not existing\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : Permission Denied\n");
                }
                if(ret == -3)
                {
                    printf("ERROR : Reached at end of file  \n");
                }
                if(ret == -4)
                {
                    printf("ERROR : It is not regular file\n");
                }
                if(ret == 0)
                {
                    printf("ERROR : File empty\n");
                }

                if(ret > 0)
                {
                    write(2,ptr,ret);
                }

                continue;
            }
            else
            {
                printf("\nERROR : Command not found!!!\n");
                continue;
            }
        }
        else if(count == 4)
        {
            if(strcmp(command[0], "lseek") == 0)
            {
                    fd = GetFDFromName(command[1]);

                    if(fd == -1)
                    {
                        printf("ERROR : Incorrect parameter\n");
                        continue;
                    }

                    ret = LseekFile(fd,atoi(command[2]),atoi(command[3]));

                    if(ret == -1)
                    {
                        printf("ERROR : Unable to perform lseek\n");
                    }
            }
            else
            {
                printf("\nERROR : Command not found!!!\n");
                continue;
            }
        }
        else
        {
            printf("\nERROR : Command not found !!!\n");
            continue;
        }
    }
    return 0;
}