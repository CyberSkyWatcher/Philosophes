
#include <iostream>
#include <ctime> // time_t time()
#include <unistd.h> // usleep
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <cmath>
#include <thread> // std::thread
#include <chrono> // std::chrono

#include "SolutionEtudiant.hpp"
#include "Header_Prof.h"



#define sem2 // a mettre dans h

pthread_t* timerThread;

// Tâches exécutant la vie de chaque philosophe

int* threadIds;		//ptr pour stockages id



// timerThread flag
bool timerRunning = false;

/// Chacune des 2 solutions doit implémenter les fonctions initialisation,
/// vieDuPhilosophe, actualiser... et terminerProgramme
/// Vous pouvez re-définir toutes ces fonctions dans #ifdef SOLUTION_1 ... #endif
/// puis plus loin dans #ifdef SOLUTION_2 ... #endif
///
/// Ou alors: déclarer 1 seule fois chaque fonction, et utiliser les defines dans
/// le corps même de l'implémentation de chaque fonction


#ifdef SOLUTION_1
void fonctionOrdonnancer (){
	if(etatsPhilosophes[0]== 1 && etatsPhilosophes[2] == 1 && etatsPhilosophes[3] == 1 && etatsPhilosophes[1] == 1){
		//gr 1 eat
		actualiserEtAfficherEtatsPhilosophes(0,2);
		actualiserEtAfficherEtatsPhilosophes(2,2);
		//actualiserEtAfficherEtatsPhilosophes(4,2);
	}
	else if(etatsPhilosophes[0] == 3 && etatsPhilosophes[2] == 3 && etatsPhilosophes[1] == 1 && etatsPhilosophes[3] == 1){

		// gr2 eat
		actualiserEtAfficherEtatsPhilosophes(1,2);
		actualiserEtAfficherEtatsPhilosophes(3,2);
		//gr1 think
		actualiserEtAfficherEtatsPhilosophes(0,4);
		actualiserEtAfficherEtatsPhilosophes(2,4);
	}
	else if(etatsPhilosophes[3] == 3 && etatsPhilosophes[1] == 3 && etatsPhilosophes[4] == 1){
		// gr3 eat
		actualiserEtAfficherEtatsPhilosophes(4,2);
		//gr2 think
		actualiserEtAfficherEtatsPhilosophes(1,4);
		actualiserEtAfficherEtatsPhilosophes(3,4);
	}

	else if(etatsPhilosophes[4] == 3 && etatsPhilosophes[0] == 5 && etatsPhilosophes[2] == 5 && etatsPhilosophes[1] == 5 && etatsPhilosophes[3] == 5){
		// gr1 and gr 2 hungry
		actualiserEtAfficherEtatsPhilosophes(0,0);
		actualiserEtAfficherEtatsPhilosophes(2,0);
		actualiserEtAfficherEtatsPhilosophes(1,0);
		actualiserEtAfficherEtatsPhilosophes(3,0);
		//gr 3 think
		actualiserEtAfficherEtatsPhilosophes(4,4);
	}
	if(etatsPhilosophes[4] == 5 ){
		actualiserEtAfficherEtatsPhilosophes(4,0);
	}



	/*switch(state_counter){
		case 0:
			actualiserEtAfficherEtatsPhilosophes(0,2);
			actualiserEtAfficherEtatsPhilosophes(2,2);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
	}
	*/


	/*for(int i; i<NB_PHILOSOPHES;i++){
		//check if someone is ready to eat
		pthread_mutex_lock(&mutexEtats);
		if(etatsPhilosophes[i] == 1){

		    // Modify the state
		    etatsPhilosophes[i] = 2;
		    // Unlock the mutex after finishing the access

		}
		else if(etatsPhilosophes[i] == 3){

			// Modify the state
			etatsPhilosophes[i] = 4;
			// Unlock the mutex after finishing the access

		}
		else if(etatsPhilosophes[i] == 5){
etatsPhilosophes[0]== 1 && etatsPhilosophes[2] == 1
			// Modify the state
			etatsPhilosophes[i] = 0;
			// Unlock the mutex after finishing the access

		}
		pthread_mutex_unlock(&mutexEtats);
	}*/
	//std::cout << "mutex not lock"<< std::endl;
	//pthread_mutex_lock(&mutexEtats);
	//std::cout << "mutexlocked"<< std::endl;

	/*//MAUVAIS CHOIX !!!!!!!!!!!!!!!!!!!
	if(etatsPhilosophes[0]== 1 && etatsPhilosophes[2] == 1 &&etatsPhilosophes[4] == 1 && etatsPhilosophes[3] == 1 && etatsPhilosophes[1] == 1){
		//gr 1 eat
		actualiserEtAfficherEtatsPhilosophes(0,2);
		actualiserEtAfficherEtatsPhilosophes(2,2);
		actualiserEtAfficherEtatsPhilosophes(4,2);
	}
	else if(etatsPhilosophes[0]== 3 && etatsPhilosophes[2] == 3 &&etatsPhilosophes[4] == 3 &&etatsPhilosophes[3] == 1 && etatsPhilosophes[1] == 1){
		//gr 1 ended eat -> think
		actualiserEtAfficherEtatsPhilosophes(0,3);
		actualiserEtAfficherEtatsPhilosophes(2,3);
		actualiserEtAfficherEtatsPhilosophes(4,3);
		// gr2 eat
		actualiserEtAfficherEtatsPhilosophes(1,2);
		actualiserEtAfficherEtatsPhilosophes(3,2);
	}
	else if(etatsPhilosophes[0]== 5 && etatsPhilosophes[2] == 5 &&etatsPhilosophes[4] == 5 &&etatsPhilosophes[3] == 3 && etatsPhilosophes[1] == 3){
		// gr1 hungry again
		actualiserEtAfficherEtatsPhilosophes(0,0);
		actualiserEtAfficherEtatsPhilosophes(2,0);
		actualiserEtAfficherEtatsPhilosophes(4,0);
		// gr2 think
		actualiserEtAfficherEtatsPhilosophes(1,4);
		actualiserEtAfficherEtatsPhilosophes(3,4);
	}
	else if(etatsPhilosophes[0]== 1 && etatsPhilosophes[2] == 1 &&etatsPhilosophes[4] == 1 &&etatsPhilosophes[3] == 5 && etatsPhilosophes[1] == 5){
		// gr1 eat
		actualiserEtAfficherEtatsPhilosophes(0,2);
		actualiserEtAfficherEtatsPhilosophes(2,2);
		actualiserEtAfficherEtatsPhilosophes(4,2);
		//gr2 hungry again
		actualiserEtAfficherEtatsPhilosophes(1,0);
		actualiserEtAfficherEtatsPhilosophes(3,0);
	}
	//pthread_mutex_unlock(&mutexEtats);
	//std::cout << "mutexunlocked"<< std::endl;
	 */
}

void* timerFunction(void* arg) {
    // Configuration du thread : il sera annulable à partir de n'importe quel point de préemption
    // (appel bloquant, appel système, etc...)
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    while (1) {
        // appel ordonnanceur
        fonctionOrdonnancer();
        // time count
        time_t currentTime = time(NULL);
        //std::cout << "Elapsed time: " << difftime(currentTime, instantDebut) << " seconds." << std::endl;

        // Sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        pthread_testcancel(); // point où l'annulation du thread est permise
    }
    return NULL;
}

void initialisation()
{
	timerRunning = false;
	// Lock the mutex
	pthread_mutex_lock(&mutexEtats);
	// Allocate memory
	etatsPhilosophes = (char*)malloc(NB_PHILOSOPHES*sizeof(char));
	// Unlock the mutex
	pthread_mutex_unlock(&mutexEtats);
	//timer alloc memorry
	timerThread = (pthread_t*)malloc(sizeof(pthread_t));


	// Allocate memory for the semaphore
	semFourchettes = (sem_t **)malloc(NB_PHILOSOPHES * sizeof(sem_t *));

	/*if (semFourchettes == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}*/

	// Create and initialize semaphores
	for (int i = 0; i < NB_PHILOSOPHES; i++) {
		semFourchettes[i] = (sem_t *)malloc(sizeof(sem_t));

		if (semFourchettes[i] == NULL) {
			fprintf(stderr, "Memory allocation failed for semaphore %d\n", i);
			exit(EXIT_FAILURE);
		}

		if (sem_init(semFourchettes[i], 0, 1) != 0) {  // Initialize semaphore with an initial value of 1 --> free for use
			fprintf(stderr, "Semaphore initialization failed for semaphore %d\n", i);
			exit(EXIT_FAILURE);
		}
	}

	/* ******************** Création des threads ***************** */
	// Allocation mémoire des ID
	threadIds = (int*)malloc(NB_PHILOSOPHES * sizeof(int));
	// allocation mémoire des threads
	threadsPhilosophes = (pthread_t*)malloc (NB_PHILOSOPHES * sizeof(pthread_t));
	for(int j = 0; j<NB_PHILOSOPHES; j++){
		//pthread_attr_t attr;
		//pthread_attr_init(&attr);
		//int a =pthread_attr_setschedpolicy(&attr,SCHED_FIFO);
		//cout<<a<<endl;
		threadIds[j] = j;
		if(pthread_create(&threadsPhilosophes[j], NULL, &vieDuPhilosophe, &threadIds[j])){
			//std::cout<<"Thread creation failed"<<std::endl;
			fprintf(stderr, "Thread initialization failed for philo %d\n", j);
			exit(EXIT_FAILURE);
		}
	}

	fprintf(stderr, "Thread initialization successfully ended for philos");

	int debug = pthread_create(&timerThread[0], NULL, &timerFunction, NULL);
	std::cout <<debug<< std::endl;
	timerRunning = true;



}

void penser (void){
	double randomValue = (double)(rand()) / RAND_MAX * DUREE_MANGE_MAX_S; // better to  use random than  rand
	sleep(randomValue);
}

void manger (void){
	double randomValue = (double)(rand()) / RAND_MAX * DUREE_MANGE_MAX_S;
	sleep(randomValue);
}


void* vieDuPhilosophe(void* idPtr)
{
    int id = * ((int*)idPtr);
    int id_1 = id+1;
    if(id == 4){
		id_1 = 0;
	}

    // Configuration du thread : il sera annulable à partir de n'importe quel point de préemption
    // (appel bloquant, appel système, etc...)
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    
    while(1) {
        
        // ***** À implémenter : *****
        // - structure permettant le contrôle du philosphe
        // - prise/relâchement des fourchettes de gauche et de droite, au bon moment
        // - ordres de changement d'état et d'actualisation de l'affichage dans la foulée
        //     (grâce à : void actualiserEtAfficherEtatsPhilosophes(int, char))
        // - simulation des actions "manger" et "penser" par des appels à usleep(...)

		switch (etatsPhilosophes[id]) {
		    case 0:
		    	std::cout << "Philo : "<< id << " is hungry" << std::endl;
				actualiserEtAfficherEtatsPhilosophes(id,1);
				//etatsPhilosophes[id] = 1;
		        break;

		    case 2:
		    	sem_wait(semFourchettes[id]);
				usleep(10000);
				sem_wait(semFourchettes[id_1]);
				std::cout << "Philo : "<< id << " managed to get forks" << std::endl;
		    	std::cout << "Philo : "<< id << " is eating" << std::endl;
		    	manger();
		    	sem_post(semFourchettes[id]);
				usleep(10000);
				sem_post(semFourchettes[id_1]);
				std::cout << "Philo "<< id << "ended eating success and dropped forks" << std::endl;
				actualiserEtAfficherEtatsPhilosophes(id,3);
		        break;

		    case 4:
		    	std::cout << "Philo : "<< id << " is thinking" << std::endl;
		    	penser();
		    	std::cout << "Philo : "<< id << " done thinking" << std::endl;
		    	actualiserEtAfficherEtatsPhilosophes(id,5);
		    	std::cout << "Philo : "<< id << " is waiting for an order" << std::endl;
				break;

		    default:
		    	break;
		        // code to be executed if expression doesn't match any of the constants
		}


    	//SPIN LOCK
    	/*if (hungry) {
			sem_wait(semFourchettes[id]);
			usleep(10000);
			sem_wait(semFourchettes[id_1]);
			std::cout << "Philo "<< id << "have forks and ready to eat" << std::endl;
			hungry = 0;
			time_for_eat = 1;
    	}

    	else if(time_for_eat){
        	//sleep((float)rand() % (float)DUREE_MANGE_MAX_S);
        	double randomValue = static_cast<double>(rand()) / RAND_MAX * DUREE_MANGE_MAX_S;
        	sleep(randomValue);
        	sem_post(semFourchettes[id]);
        	usleep(10000);
        	sem_post(semFourchettes[id_1]);
        	std::cout << "Philo "<< id << "ended eating success" << std::endl;
        	time_for_eat = 0;
        	time_for_think = 1;
        }
        else if(time_for_think){
			//sleep((float)rand() % (float)DUREE_PENSE_MAX_S);
        	double randomValue = static_cast<double>(rand()) / RAND_MAX * DUREE_MANGE_MAX_S; // better to  use random than  rand
        	sleep(randomValue);
        	std::cout << "Philo "<< id << "ended thinking and hungry again" << std::endl;
        	time_for_think = 0;
        	hungry = 1;
		}*/
        pthread_testcancel(); // point où l'annulation du thread est permise
    }
    
    return NULL;
}


void actualiserEtAfficherEtatsPhilosophes(int idPhilosopheChangeant, char nouvelEtat)
{
    // ***** À IMPLÉMENTER : PROTECTION ÉTATS *****
    // ***** À IMPLÉMENTER : PROTECTION CONSOLE *****
    // Lock the mutex
    pthread_mutex_lock(&mutexEtats);
    etatsPhilosophes[idPhilosopheChangeant] = nouvelEtat;
    //Unlock the mutex
    pthread_mutex_unlock(&mutexEtats);
    /*for (int i=0;i<NB_PHILOSOPHES;i++) {
        if (i==idPhilosopheChangeant)
            std::cout << "*";
        else
            std::cout << " ";
        std::cout << etatsPhilosophes[i];
        if (i==idPhilosopheChangeant)
            std::cout << "* ";
        else
            std::cout << "  ";
    }
    std::cout << "          (t=" << difftime(time(NULL), instantDebut) << ")" << std::endl;*/
}





void terminerProgramme()
{
    for (int i = 0; i < NB_PHILOSOPHES; i++) {
        sem_destroy(semFourchettes[i]);
        free(semFourchettes[i]);
    }

    free(semFourchettes);
    std::cout << "Forks destroyed" << std::endl;

    for (int i = 0; i < NB_PHILOSOPHES; i++){
    	pthread_cancel(threadsPhilosophes[i]);
    }
    free(threadsPhilosophes);
    free(threadIds);
    free(etatsPhilosophes);
    free(timerThread);

    std::cout << "Philos destroyed" << std::endl;

    timerRunning = false;
    //pthread_join(&timerThread);
    //exit(EXIT_SUCCESS);
}


#endif  // #ifdef OLUTION_1
