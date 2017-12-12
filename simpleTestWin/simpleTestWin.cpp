#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex myMutex;
//this is the thread funciton that is called by each thread
//just prints the id of thread with mutex protection
void threadFuncWithMutex()
{	
	myMutex.lock();
	cout<<"My id is "<< this_thread::get_id() <<endl;
	cout<<"My id time 100 is "<< this_thread::get_id() <<"00 ."<<endl;
	myMutex.unlock();
}
//this is the thread funciton that is called by each thread
//just prints the id of thread without mutex protection
void threadFuncWithoutMutex()
{	
	// myMutex.lock();
	cout<<"My id is "<<this_thread::get_id()<<endl;
	cout<<"My id time 100 is "<< this_thread::get_id() <<"00 ."<<endl;
	// myMutex.unlock();
}
int main()
{
	cout<<"Program execution successful"<<endl;
	cout<<"Following is the execution with Mutex protection"<<endl;

//launch the threads
	std::thread myThread1(threadFuncWithMutex);
	std::thread myThread2(threadFuncWithMutex);
//wait for threads
	myThread1.join();
	myThread2.join();

//launch the threads
	cout << "Following is the execution without Mutex protection" << endl;
	cout << "Brace yourself for some error or undefined behavior" << endl;
	std::thread myThread3(threadFuncWithoutMutex);
	std::thread myThread4(threadFuncWithoutMutex);
//wait for threads
	myThread1.join();
	myThread2.join();

	return 0;
}