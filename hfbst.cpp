#include <iostream>
#include <vector>
#include <String.h>
#include <cstdlib>
#include "ImmutableDictionary.h"

#define MAX_TREE_HT 100 



struct Node {
    	int data[2];
	Node* next;
	Node(int val1, int val2) : next(nullptr) {
        	data[0] = val1;
        	data[1] = val2;
    	}
};

class ScheduleMaker {
	public:
    		static const int ROWS = 3;
    		static const int COLS = 7;
    		std::vector<std::vector<int>> computeMatrixAND(
	        const std::vector<std::vector<int>>& matrix1,
        	const std::vector<std::vector<int>>& matrix2) {
                std::vector<std::vector<int>> result(ROWS, std::vector<int>(COLS, 0));
        		for (int i = 0; i < ROWS; i++) {
            			for (int j = 0; j < COLS; j++) {
			                result[i][j] = matrix1[i][j] & matrix2[i][j];
            			}
        		}
	        	return result;
    		}
    
		std::vector<std::vector<int>> createValuesMatrix(
			const std::vector<int>& values, int cols) {
			std::vector<std::vector<int>> matrix(ROWS, std::vector<int>(cols, 0));
			for (int i = 0; i < ROWS && i < values.size(); i++) {
				for (int j = 0; j < cols; j++) {
					matrix[i][j] = values[i];
			    	}
			}
			return matrix;
		}
    
		std::vector<std::vector<int>> addMatrices(
			const std::vector<std::vector<int>>& matrix1,
			const std::vector<std::vector<int>>& matrix2) {
			
			std::vector<std::vector<int>> result(ROWS, std::vector<int>(COLS, 0));
				for (int i = 0; i < ROWS; i++) {
				    for (int j = 0; j < COLS; j++) {
					result[i][j] = matrix1[i][j] + matrix2[i][j];
				    }
				}
			return result;
		}


		Node* addNode(Node* head, int val1, int val2) {
			Node* newNode = new Node(val1, val2);
			if (!head) {
			    return newNode;
			}
			Node* current = head;
			while (current->next) {
			    current = current->next;
			}
			current->next = newNode;
			return head;
		}

		Node* scheduleMaker(const std::vector<std::vector<int>> &matrix1,
				const std::vector<std::vector<int>> &values) {
			
			Node* resultList = nullptr;
			
			auto andProduct = computeMatrixAND(values, matrix1);
			auto sumMatrix = addMatrices(andProduct, matrix1);
			int k = 0;
			int loopSum;
			for (int j = 0; j < COLS; j++) {
				k += 1;
				for (int i = 0; i < ROWS; i++) {
					if (sumMatrix[i][j] > 0) {
						loopSum = i + 1 + j*3;
					    	if (resultList == nullptr) {
							resultList = addNode(nullptr, loopSum, sumMatrix[i][j] );
						} else {
							resultList = addNode(resultList, loopSum, sumMatrix[i][j] );
						}
							
				}
			    }
			}
			
		return resultList;
	    }	
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
	    std::cout << "[" << current->data[0] << "," << current->data[1] << "] -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}



int main() {
	ScheduleMaker maker;
	Dict 
	std::vector<std::vector<int>> matrix1 = {
        	{0, 0, 0, 0, 0, 0, 0},
	        {0, 0, 0, 0, 1, 1, 0},
	        {0, 1, 1, 1, 0, 0, 0}
	};
	std::vector<std::vector<int>> values = {
        	{0, 0, 0, 0, 0, 0, 0},
	        {0, 0, 0, 0, 0, 0, 0},
	        {0, 0, 1, 1, 0, 0, 0}
	};
  	Node* result = maker.scheduleMaker(matrix1, values); 
	printList(result);

//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
//	int freq[] = { 5, 9, 12, 13, 16, 45 }; 
//	int size = sizeof(arr) / sizeof(arr[0]); 
//	HuffmanCodes(arr, freq, size);
    	return 0;
}
