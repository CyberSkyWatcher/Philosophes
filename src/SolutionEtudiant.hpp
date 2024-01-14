

#ifndef SolutionEtudiant_hpp
#define SolutionEtudiant_hpp
#include <iostream>
#include <ctime> // time_t time()
#include <unistd.h> // usleep
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <cmath>
#include <thread> // std::thread
#include <chrono> // std::chrono
#include <iostream>
#include <fstream>
#include <ctime>

#define sem2
// Codes ANSI pour les couleurs
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Dans ce fichier, rajouter tout ce qui pourrait manquer pour programmer la solution
void penser(void);
void manger(void);
void *timerFunction(void *arg);
void OrdonnancerAvecSemaphoresFinal();

#endif /* SolutionEtudiant_hpp */
