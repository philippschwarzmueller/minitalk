# minitalk
The minitalk project of 42-schools corecurriculum features two programs that communicate with each other using Signals.

## how it works
- The server prints its PID on start
- The client executable takes two parameters: The PID of the server and a string
- The subject of the project only allows using SIGUSR1 and SIGUSR2 so the client first breaks the string down into bits and puts them into a string. Then iterating over the string the client sends either SIGUSR1 (0) or SIGUSR2 (1) to the server. The server adds a char to the received string for every 8 signals received.
- Once the server receives the terminating '\0' char it sends a signal to the client to confirm successfull transmission.
