#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/shm.h>

#include <sys/types.h>

#include <unistd.h>



#include <stdio.h>





#include <stdlib.h>



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





#include <cstring>

#include <iostream>

#include <string>



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

bool checkGrid(const char* myPtr, int n) {

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

                myPtr[i];  // This assigns specific char to be a seperate var

            if (myPtr[i] != '!') {

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



    while (j <= ((n * n) -

                 1)) {  // check every 3, but skip the first and last n-1 chars.



        // check for X's

        int rem = j % (n + 1);  // use modulus to find diagonal X pattern

        if (rem == 0) {

            char iChar =

                myPtr[j];  // This assigns specific char to be a seperate var

            if (myPtr[j] != '!') {

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

                char iChar = myPtr[k];  // This assigns specific char to be a

                                        // seperate var

                                        // std::cout << iChar;

                if (myPtr[k] != '!') {

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

            myPtr[L];  // This assigns specific char to be a seperate var

                       // std::cout << iChar;

        if (myPtr[L] != '!') {

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

int main() {

    // pid_t pid;

    // pid = fork ();

    bool didIWin = false;

    // START TEST2 // 3 in a row.



    // ok so we need to ask the 1st process what the size is

    int userInput;  // Declare an integer variable to store the input



    std::cout << "Enter an integer: ";

    std::cin >> userInput;  // Use cin to read the integer input



    std::cout << "You entered: " << userInput << std::endl;



    int x = userInput;

    int y = userInput;

    int n = userInput;



    // make a string that is 5*5 chars long

    int length = userInput * userInput;

    char nSquare[length] = "";

    // nSquare[0] =  '-';

    for (int nS = 0; nS <= ((userInput * userInput) - 1); nS++) {

        nSquare[nS] = '-';

    }



    printGrid(nSquare, n);  // method call to print my pointerArray pseudostring



    char* myPtr = nSquare;



    // printf(myPtr);



    // MAIN

   

    while (didIWin == false) { // loops until game ends

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



            if (refGrid(myPtr, n, xInput, yInput) == true) {

                myPtr[loc] = '!';

                safe = true;

            } else {

                printf("try again, enter a valid location");

            }

        } 

        

        // check for a win

        printGrid(myPtr, n);



        didIWin = checkGrid(myPtr, n);

        std::cout << didIWin;

        









      //PASS MESSAGE











/* the size (in bytes) of shared memory object */



const int SIZE = 4096;



/* name of the shared memory object */



const char *name = "OS";



/* strings written to shared memory */



const char *message_0 = myPtr;



const char *message_1 = "";





/* shared memory file descriptor */



int fd;



/* pointer to shared memory obect */



char *ptr;



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



//sprintf(ptr,"%s",message_1);



//ptr += strlen(message_1);



sleep(10);











































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



            // Remove the shared memory object

            unlink(name);

        }

    }

}



// BACK TO MAIN

    }



    std::cout << didIWin;

}

