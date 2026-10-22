#include "interface.h"
#include <iostream>
#include "ReadWriteFile.h"
#include <sstream> 
using namespace std;
//  ./structures --file file.data.txt --querry 'FAE list2 5 5' 

void Action(ForwardList* fList, string cmd, string line1, string line2, int* sz){
	switch (cmd[1]){
		case 'A':{ // Add
			switch (cmd [2]){
				case 'A':{ // After
					AddAfter(fList, line1, line2, sz);
					break;
				} 
				case 'S':{ // Start
					AddStart(fList, line1, sz);
					break;
				} 
				case 'B':{ // Before
					AddBefore(fList, line1, line2, sz);	
					break;
				} 
				case 'E':{ // End
					AddEnd(fList, line1, sz);	
					break;
				}
				default:
					cout << "unknow command\n";
			}
			break;
		}
		case 'D':{ // Delete
			switch (cmd [2]){
				case 'L':{ // List
					DeleteList(fList, sz);	
					break;
				} 
				case 'S':{ // Start
					DeleteStart(fList, sz);
					break;
				} 
				case 'V':{ // Value
					DeleteByValue(fList, line1, sz);
					break;
				} 
				case 'E':{ // End
					DeleteEnd(fList, sz);
					break;
				}
				case 'A':{ // After
					DeleteAfter(fList, line1, sz);
					break;
				}
				case 'B':{ // Before
					DeleteBefore(fList, line1, sz);
					break;
				}

				default:
					cout << "unknow command\n";
			}
			
			break;
		}
		case 'G':{ // get
			cout << GetPositionByValue(fList, line1) << endl;	
			break;
		}
		case 'O':{ // output
			OutputList(fList);
			break;
		}
		case 'S':{ // size
			cout << ListSize(fList) << endl;	
			break;
		}
		default:
			cout << "unknow command\n";
	}
}


void Action(DoubleList* dList, string cmd, string line1, string line2, int* sz){
	switch (cmd[1]){
		case 'A':{ // Add
			switch (cmd [2]){
				case 'A':{ // After
					AddAfter(dList, line1, line2, sz);
					break;
				} 
				case 'S':{ // Start
					AddStart(dList, line1, sz);
					break;
				} 
				case 'B':{ // Before
					AddBefore(dList, line1, line2, sz);	
					break;
				} 
				case 'E':{ // End
					AddEnd(dList, line1, sz);	
					break;
				}
				default:
					cout << "unknow command\n";
			}
			break;
		}
		case 'D':{ // Delete
			switch (cmd [2]){
				case 'L':{ // List
					DeleteList(dList, sz);	
					break;
				} 
				case 'S':{ // Start
					DeleteStart(dList, sz);
					break;
				} 
				case 'V':{ // by Value
					DeleteByValue(dList, line1, sz);
					break;
				} 
				case 'E':{ // End
					DeleteEnd(dList, sz);
					break;
				} 
				case 'B':{ // Before
					DeleteBefore(dList, line1, sz);
					break;
				} 
				case 'A':{ // After
					DeleteAfter(dList, line1, sz);
					break;
				} 
				
				default:
					cout << "unknow command\n";
			}
			
			break;
		}
		case 'G':{ // get
			cout << GetPositionByValue(dList, line1) << endl;	
			break;
		}
		case 'O':{ // output
			switch (cmd[2]){
				case 'H':{ // с начала
					OutputHList(dList);
					break;
				}
				case 'T':{ // с конца
					OutputTList(dList);
					break;
				}
			}
			break;
		}
		case 'S':{ // size
			cout << ListSize(dList) << endl;	
			break;
		}
		default:
			cout << "unknow command\n";
	}
}

void Action(string* array, int* capacity, int* sz, string cmd, string line1, string line2){
	switch (cmd[1]){
		case ('A'):{
			switch (cmd[2]){
				case 'E':{ // End
						ArrAddEnd(array, line1, sz);
					break;
				} 
				case 'I':{ // Index
					ArrAddByIndex(array, line1, stoi(line2), sz);
					break;
				} 
			}
			break;
		}
		case 'G':{
			cout << ArrGetElem(array, stoi(line1), sz) << endl;
			break;
		}
		case 'D':{
			ArrDelByIndex(array, stoi(line1), sz);
			break;
		}
		case 'E':{
			ArrReplaceByIndex(array, line1, stoi(line2), sz);
			break;
		}
		case 'P':{
			ArrPrint(array, sz);
			break;
		}
	}
}

void Action(Queue* queue, string cmd, string line1){
	switch (cmd[1]){
		case 'A':{
			QueuePush(queue, line1);
			break;
		}
		case 'D':{
			QueuePop(queue);
			break;
		}
		case 'P':{
			QueuePrint(queue);
			break;
		}
		case 'C':{
			QueueClear(queue);
			break;
		}	
	}
}


void Action(Stack* stack, string cmd, string line1){
	switch (cmd[1]){
		case 'A':{
			StackPush(stack, line1);
			break;
		}
		case 'D':{
			StackPop(stack);
			break;
		}
		case 'P':{
			StackPrint(stack);
			break;
		}
		case 'C':{
			StackClear(stack);
			break;
		}
	}
}

void Action(AVL_Tree* tree, string cmd, string line1) {
    switch (cmd[1]) {
        case 'A': {
			int lineToSend = stoi(line1);
			TreeAddElem(tree, lineToSend); 
			break; 
		}
        case 'D': { 
			int lineToSend = stoi(line1);
			TreeDelElem(tree, lineToSend);
			break; 
		}
        case 'O': {
			switch (cmd[2]){
				case '1':{
					cout << "InOrder: ";
					TreePrintInOrder(tree);	
					break;
				}
				case '2':{
					cout << "PreOrder:  ";
					TreePrintPreOrder(tree);
					break;
				}
				case '3':{
					cout << "PostOrder: ";
					TreePrintPostOrder(tree);
					break;
				}
			}
			break; 
		}
        case 'C': { 
			TreeClear(tree); 
			break; 
		}
    }
}

void Action(string cmd, string name, string filename){
	switch (cmd[1]){
		case 'F':{
			AddStructureToFile(filename, "Stack", name);
			break;
		}
		case 'D':{
			AddStructureToFile(filename, "Queue", name);		
			break;
		}
		case 'A':{
			AddStructureToFile(filename, "Array", name);		
			break;
		}	
		case 'S':{
			AddStructureToFile(filename, "ForwardList", name);		
			break;
		}	
		case 'Q':{
			AddStructureToFile(filename, "DoubleList", name);		
			break;
		}	
		case 'T':{
			AddStructureToFile(filename, "AVL_Tree", name);		
			break;
		}	
	}	
}


int main(int argc, char* argv[]){
	string filename = "";
	stringstream querry;
	string cmd = "";
	string name = "";
	string line1 = "0";
	string line2 = "0";

	for (int i = 0; i < argc; i++){
		if (string(argv[i]) == "--file"){
			filename = argv[i+1];
			filename.erase(0, 5);
		}
		if (string(argv[i]) == "--querry"){
			querry.str(argv[i+1]);				
		}
	}

	/* нужно распарсить querry впринципе все понятно, но может быть 3 варианта команд:
	c index и value,
	c value.
	без всего*/

	int i = 0;
	string line = "";
	while (querry >> line){
		if (i == 0){
			cmd = line;
		}
		if (i == 1){
			name = line;
		}
		if (i == 2){
			line1 = line;
		}
		if (i == 3){
			line2 = line;
		}
		i++;
	}
/*
	cout << "filename: " << filename << endl;
	cout << "cmd: " << cmd << endl;
	cout << "nameOfStruct: " << name << endl;
	cout << "line1: " << line1 << endl;
	cout << "line2: " << line2 << endl << endl;
*/	
	int sz = 0;
	switch (cmd[0]){
		case 'F':{
//			cout << "Create ForwardList\n";
			ForwardList fList = {nullptr};
//			cout << "ReadForwardList()\n";
			ReadForwardList(&fList, filename, name, &sz);
//			cout << "Action()\n";
			Action(&fList, cmd, line1, line2, &sz);
//			cout << "WriteStucture()\n";
			WriteStructure(&fList, filename, name);
//			cout << "RewriteFile()\n";
			RewriteFile(&fList, filename, name);
			break;
		}
		case 'D':{
//			cout << "Create DoubleList\n";
			DoubleList dList = {nullptr};
//			cout << "ReadDoubleList\n";
			ReadDoubleList(&dList, filename, name, &sz);
//			cout << "Action\n";
			Action(&dList, cmd, line1, line2, &sz);
//			cout << "WriteStructure\n";
			WriteStructure(&dList, filename, name);
//			cout << "RewriteFile\n";
			RewriteFile(&dList, filename, name);
			break;
		}
		case 'A':{
		
			int capacity = 5;
			int sz = 0;
			string* array = new string[5];
			ReadArray(&array, &capacity, &sz, filename, name);
			ArrCheckSize(&array, &sz, &capacity);
			Action(array, &capacity, &sz, cmd, line1, line2);
			ArrPrint(array, &sz);
			WriteStructure(&array, &capacity, &sz, filename, name);
			RewriteFile(&array, filename, name);
			break;
		}
		case 'Q':{
			Queue queue = {nullptr, nullptr};	
			ReadQueue(&queue, filename, name);
//			cout << "Action\n";
			Action(&queue, cmd, line1);
//			cout << "WriteStructure\n";
			WriteStructure(&queue, filename, name);
//			cout << "RewriteFile\n";
			RewriteFile(&queue, filename, name);
			break;
		}
		case 'S':{
			Stack stack = {nullptr};	
			ReadStack(&stack, filename, name);
			StackPrint(&stack);
//			cout << "Action\n";
			Action(&stack, cmd, line1);
			StackPrint(&stack);
//			cout << "WriteStructure\n";
			WriteStructure(&stack, filename, name);
//			cout << "RewriteFile\n";
			RewriteFile(&stack, filename, name);
			break;
		}
		case 'T':{
			AVL_Tree tree = {nullptr};	
			ReadTree(&tree, filename, name);
//			cout << "Action\n";
			Action(&tree, cmd, line1);
//			cout << "WriteStructure\n";
			WriteTree(&tree, filename, name);
//			cout << "RewriteFile\n";
			RewriteFile(&tree, filename, name);
			break;
		}
		case 'N':{
			Action(cmd, name, filename);
		}
		default:
			cout << "unknow command\n";
	}
}
