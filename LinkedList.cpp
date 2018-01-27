#include <iostream>
#include <string>
using namespace std;

struct list{
	int data;
	list* next;
};

typedef list* nodePtr;

void addTolist(nodePtr& hdList,int value);
int FindItem(nodePtr hdList, int value);
void PrintAList(nodePtr hdList);
void PrintReverseList(nodePtr hdList);
void DeleteList(nodePtr hdList);
void DeleteElements(nodePtr& hdList, int value);
void AddOrdered(nodePtr& hdList, int value);
void ReverseAList(nodePtr hdList);
nodePtr ReverseAListLoop(nodePtr hdList);
int FindSum(nodePtr hdList);
int CountNodes(nodePtr hdList);
nodePtr FindMinimum(nodePtr hdList);
nodePtr FindMaximum(nodePtr hdList);
void BubbleSort(nodePtr& hdList);
int GetNumberofElements(nodePtr hdList, int value);
nodePtr LastElement(nodePtr hdList);
bool isPresent(nodePtr hdList, int value);
void DeleteElement(nodePtr& hdList, int value);

int main(){

}

void addTolist(nodePtr& hdList,int value){
	if(hdList == NULL){
		hdList = new nodePtr;
		hdList->data = value;
		hdList->next = NULL;
	}
	else{
		nodePtr temp = new nodePtr;
		temp->data = value;
		temp->next = hdList;
		hdList = temp;
	}
}

void PrintAList(nodePtr hdList){
	if(hdList == NULL){
		return;
	}
	else{
		cout << hdList->data << " ";
		PrintAList(hdList->next);
	}
}

void PrintReverseList(nodePtr hdList){
	if(hdList == NULL){
		return;
	}
	else{
		PrintAList(hdList->next);
		cout << hdList->data << " ";
	}
}

int FindItem(nodePtr hdList, int value){
	int counter;
	if(hdList == NULL){
		return;
	}
	else{
		while(hdList != NULL){
			if(hdList->data == value){
				counter++;
			}
			hdlist = hdList->next;
		}
	}
	return counter;
}

void DeleteElement(nodePtr& hdList, int value){ 			//deletion of first instance
	if(hdList == NULL){
		return;
	}
	else if(hdList!=NULL && hdList->next==NULL && hdList->data == value){
		delete hdList;
		return;
	}
	else{
		bool found = false;
		nodePtr prev = hdList;
		nodePtr curr = prev->next;
		while(curr!=NULL&&!found){
			if(curr->data == value){
				prev->next = curr->next;
				delete curr;
				found = true;
			}
			prev = prev->next;
			curr = prev->next;
		}
	}
}

void DeleteElements(nodePtr& hdList, int value){ 			//deletion of all instances
	if(hdList == NULL){
		return;
	}
	else if(hdList!=NULL && hdList->next==NULL && hdList->data == value){
		delete hdList;
		return;
	}
	else{
		nodePtr prev = hdList;
		nodePtr curr = prev->next;
		while(curr!=NULL){
			if(curr->data == value){
				prev->next = curr->next;
				delete curr;
			}
			prev = prev->next;
			curr = prev->next;
		}
	}
}

void DeleteList(nodePtr hdList){
	nodePtr temp;
	if(hdList == NULL){
		return;
	}
	else{
		temp = hdList;
		hdList = hdList->next;
		delete temp;
		DeleteList(hdList);
	}
}

void AddOrdered(nodePtr& hdList, int value){
	if(hdList == NULL){
		hdList = new nodePtr;
		hdList->data = value;
		hdList->next = NULL;
		return;
	}
	else if(hdList->data > value){
		nodePtr temp = new nodePtr;
		temp->data = value;
		temp->next = hdList;
		hdList = temp;
	}
	else{
		bool found = false;
		nodePtr prev = hdList;
		nodePtr curr = prev->next;
		while(curr!=NULL && !found){
			if(curr->data > value){
				found = true;
			}
			else{
				prev = prev->next;
				curr = prev->next;
			}
		}
		nodePtr newNode = new nodePtr;
		newNode->data = value;
		newNode->next = NULL;
		prev->next = newNode;
		newNode->next = curr;
	}
}

void ReverseAList(nodePtr hdList){
	if(hdList == NULL){
		return;
	}
	else{
		ReverseAList(hdList->next);
		addTolist(hdList,hdList->data);
	}
}

nodePtr ReverseAListLoop(nodePtr hdList){
	if(hdList == NULL){
		return 0;
	}
	else{
		nodePtr newHeadList = new nodePtr;
		newHeadList->data = hdList->data;
		newHeadList->next = NULL;
		nodePtr temp;
		hdList = hdList->next;
		while(hdList!=NULL){
			temp = new nodePtr;
			temp->data = hdList->data;
			temp->next = newHeadList;
			newHeadList = temp;
			hdList = hdList->next;
		}
	}
	return newHeadList;
}

int CountNodes(nodePtr hdList){
	if(hdList==NULL){
		return 0;
	}
	else{
		return 1 + CountNodes(hdList->next);
	}
}

int FindSum(nodePtr hdList){
	if(hdList == NULL){
		return 0;
	}
	return hdList->data += FindSum(hdList->next);
}

nodePtr FindMinimum(nodePtr hdList){
	if(hdList == NULL){
		return hdList;
	}
	else{
		nodePtr min = hdList->next;
		while(hdList != NULL){
			if(hdList->data < min->data){
				min = hdList;
			}
			hdList = hdList->next;
		}
		return min;
	}
}

nodePtr FindMaximum(nodePtr hdList){
	if(hdList == NULL){
		return hdList;
	}
	else{
		nodePtr max = hdList->next;
		while(hdList != NULL){
			if(hdList->data > max->data){
				max = hdList;
			}
			hdList = hdList->next;
		}
		return max;
	}
}

void BubbleSort(nodePtr& hdList){
	if(hdList == NULL){
		return;
	}
		bool swapped;
		do{
			nodePtr prev = hdList;
			nodePtr curr = prev->next;
			nodePtr next = curr->next;
			swapped = false;
			if(hdList->data > curr->data){
				nodePtr temp = hdList;
				hdList = hdList->next;
				temp->next = hdList->next;
				hdList->next = temp;
			}
			while(next!=NULL){
				if(curr->data > next->next){
					curr->next = next->next;
					next->next = curr;
					prev->next = next;
					swapped = true;
				}
				prev = prev->next;
				curr = prev->next;
				next = curr->next;
			}
		}while(swapped);
	}
}

int GetNumberofElements(nodePtr hdList, int value){
	if(hdList==NULL){
		return 0;
	}
	else{
		if(hdList->data==value){
			return  1 + GetNumberofElements(hdList->next,value);
		}
		else{
			return  GetNumberofElements(hdList->next,value);
		}
	}
}

nodePtr LastElement(nodePtr hdList){
	if(hdList == NULL){
		return -1;
	}
	else{
		if(hdList->next == NULL){
			return hdList;
		}
		else{
			LastElement(hdList->next);
		}
	}
}

bool isPresent(nodePtr hdList, int value){
	if(hdList == NULL){
		return false;
	}
	else{
		if(hdList->data == value){
			return true;
		}
		else{
			isPresent(hdList->next,value);
		}
	}
}

nodePtr FindElement(nodePtr hdList){
	if(hdList == NULL){
		return hdList;
	}
	else{
		if(hdList->data == value){
			return hdList;
		}
		else{
			FindElement(hdList->next,value);
		}
	}
}
