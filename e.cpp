#include <stdio.h>



#include <stdlib.h>



#include <fcntl.h>



#include <sys/shm.h>



#include <sys/stat.h>



#include <stdio.h>



#include <stdlib.h>



#include <string.h>



#include <fcntl.h>



#include <sys/shm.h>



#include <sys/stat.h>



#include <unistd.h>



#include <sys/mman.h>



#include <cmath>

#include <sys/mman.h>

#include <iostream>



#include <stdio.h>



#include <stdlib.h>



#include <string.h>



#include <fcntl.h>



#include <sys/shm.h>



#include <sys/stat.h>



#include <unistd.h>



#include <sys/mman.h>



// Add checkers from the ticTac file



// Function to print a 2D character array of any size

void printGrid(const char* nSquare, int n) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            std::cout << nSquare[i * n + j];

        }

        std::cout << std::endl;

    }

}



bool refGrid(const char* nSquare, int n, int xInput, int yInput) {

    bool safe = true;

    int loc = (n * yInput) + xInput;

    if (nSquare[loc] != '-') {

        safe = false;

    }

    return safe;

}



// Function to convert a starchar into a 2d array

bool checkGrid(const char* ptr, int n) {

    bool winner = false;



    // Diagonal / check

    bool winCond1 = true;

    int i = n - 1;  // scale to n



    while (i <= ((n * n) -

                 n)) {  // check every 3, but skip the first and last n-1 chars.



        // check for X's

        int rem = i % (n - 1);  // use modulus to find diagonal X pattern

        if (rem == 0) {

            char iChar =

                ptr[i];  // This assigns specific char to be a seperate var

            if (ptr[i] != '$') {

                winCond1 = false;  // turns off wincondition, whenever there is

                                   // no X in a place where an x would be.

            }

        }

        i++;

    }



    if (winCond1 == true) {

        std::cout << " Diaganal a" << n << " in a row";

        winner = true;

    }



    // Diagonal \ check

    bool winCond3 = true;

    int j = 0;  // scale to n



    while (j <= ((n * n) - 1)) {  // check every 3, but skip the first and last n-1 chars.



        // check for X's

        int rem = j % (n + 1);  // use modulus to find diagonal X pattern

        if (rem == 0) {

            char iChar = ptr[j];  // This assigns specific char to be a seperate var

            if (ptr[j] != '$') {

                winCond3 = false;  // turns off wincondition, whenever there is

                                   // no X in a place where an x would be.

            }

        }

        j++;

    }



    if (winCond3 == true) {

        std::cout << " Diaganal a" << n << " in a row";

        winner = true;

    }



    // Vetical check

    bool winCond2 = true;

    int vertTally = 0;

    int k = 0;  // scale to n

    int offsetText = 0;

    for (int offset = 0; offset < n; offset++) {

        while (k <=

               ((n * n) -

                1)) {  // check every 3, but skip the first and last n-1 chars.

                       // check for X's

            int rem = k % (n);  // use modulus to find diagonal X pattern

            if (rem == offset) {

                char iChar = ptr[k];  // This assigns specific char to be a

                                        // seperate var

                                        // std::cout << iChar;

                if (ptr[k] != '$') {

                    winCond2 =

                        false;  // turns off wincondition, whenever there is no

                                // X in a place where an x would be.

                    vertTally = 0;

                } else {

                    vertTally++;

                }

            }

            if (winCond2 == false) {

                break;

            }

            k++;

        }

        if (winCond2 == true) {

            break;

        }

        winCond2 = true;

        k = 0;  // reset k for the end of the loop, to shift into counting in

                // the next collumn

        offsetText++;

    }



    if (vertTally == n) {

        std::cout << " vertical " << n << " in a row, style " << offsetText;

        winner = true;

    }



    // Horizontal check

    bool winCond4 = true;

    int pointTally = 0;

    int L = 0;  // scale to n

    while (L <= ((n * n) -

                 1)) {  // check every 3, but skip the first and last n-1 chars.

                        // check for X's

        char iChar =

            ptr[L];  // This assigns specific char to be a seperate var

                       // std::cout << iChar;

        if (ptr[L] != '$') {

            // winCond = false; // turns off wincondition, whenever there is no

            // X in a place where an x would be.

            L = (L - pointTally) + n;

            pointTally = 0;

        } else {

            pointTally++;

            L++;

        }

        if (pointTally == n) {

            break;

        }

    }



    if (pointTally == n) {

        //   std::cout << " horizontal " << n << " in a row, style ";

        winner = true;

    }



    return winner;

}































































int main()



{



bool didIWin = false;

while (didIWin == false) { // loops until game ends



/* the size (in bytes) of shared memory object */



const int SIZE = 4096;



/* name of the shared memory object */



const char *name = "OS";



/* shared memory file descriptor */



int fd;



/* pointer to shared memory obect */



char *ptr;

int ptrLength = 0; // use the null terminator to count

// Recieve Message



bool getMessagea = false;

bool getMessageb = false;



while (!getMessagea || !getMessageb) {

    getMessagea = false;

    getMessageb = false;



    int fd;

    char *ptr;



    // Open the shared memory object

    fd = open(name, O_RDWR, 0666);

    if (fd == -1) {

        perror("shm_open");

        printf("Timed out, retrying\n");

        getMessagea = false;

    } else {

        getMessagea = true;



        // Memory map the shared memory object

        ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

        if (ptr == MAP_FAILED) {

            perror("mmap");

            printf("Timed out, retrying\n");

            getMessageb = false;

        } else {

            getMessageb = true;

            printf("Received message: %s\n", ptr);



            // Unmap the memory and close the file descriptor

            munmap(ptr, SIZE);

            close(fd);



 /* read from the shared memory object */

char *ptr = ptr;









int ptrLength = 0; // use the null terminator to count

while (ptr[ptrLength] != '\0'){

	ptrLength++;

}



std::cout << "my length is: " << ptrLength;

//std::cout << ptr;

printf("%s", ptr);

//printf("%s",(char *)ptr);

/* remove the shared memory object */



unlink(name);



    }

}

}



//return 0;

























    // MAIN TIC TAC

    

    int n = sqrt(ptrLength); // establish the dimension of the grid

   

    

        bool safe = false;

        

        // input section

        while (safe == false) { // loops until input is valid

            

            // FILL IN AN X

            int xInput;  // Declare an integer variable to store the input



            std::cout << "Enter an xInput: ";

            std::cin >> xInput;  // Use cin to read the integer input



            std::cout << "You entered: " << xInput << std::endl;



            int yInput;  // Declare an integer variable to store the input



            std::cout << "Enter an xInput: ";

            std::cin >> yInput;  // Use cin to read the integer input



            std::cout << "You entered: " << yInput << std::endl;



            // an alg to fill it in.



            int loc = (n * yInput) + xInput;



            // make sure a char isn't already there



            if (refGrid(ptr, n, xInput, yInput) == true) {

                ptr[loc] = '$';

                safe = true;

            } else {

                printf("try again, enter a valid location");

            }

        } 

        

        // check for a win

        printGrid(ptr, n);



        didIWin = checkGrid(ptr, n);

        std::cout << didIWin;































































































//SEND MESSAGE BACK



/* the size (in bytes) of shared memory object */





/* name of the shared memory object */







/* strings written to shared memory */



const char *message_0 = ptr;



const char *message_1 = "";





/* shared memory file descriptor */



fd;



/* pointer to shared memory obect */



*ptr;



/* create the shared memory object */



fd = open(name,O_CREAT | O_RDWR,0666);

if (fd == -1){

	perror("shm_open");

	return 1;

}







/* configure the size of the shared memory object */



ftruncate(fd, SIZE);





/* memory map the shared memory object */



ptr = (char *)



mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

if(ptr == MAP_FAILED){

printf("");

perror("mmap");

return 1;	

}



/* write to the shared memory object */

printf("");

sprintf(ptr,"%s",message_0);



ptr += strlen(message_0);



sprintf(ptr,"%s",message_1);



ptr += strlen(message_1);



sleep(10);

































}











}

