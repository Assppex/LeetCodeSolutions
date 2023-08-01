// MergingLinkedLists.cpp: определяет точку входа для приложения.
//

#include "MergingLinkedLists.h"

using namespace std;


struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (!list1 && !list2) {
			return NULL;
		}
		else if (!list2) {
			return list1;
		}
		else if (!list1) {
			return list2;
		}
		ListNode* cursor1 = list1;
		ListNode* cursor2 = list2;
		ListNode* tmp = NULL;
		ListNode* tmp2 = NULL;
		bool bigger = false;

		while (cursor1 && cursor2) {
			bigger = false;
			tmp = cursor2->next;
			tmp2 = cursor1->next;

			if (cursor1->val >= cursor2->val && cursor2->next != NULL && cursor1->val <= cursor2->next->val) {

				cursor2->next = cursor1;
				cursor2->next->next = tmp;

				if(cursor2->next){
				cout << "Next curs2  " << cursor2->next->val << endl;
				}
				//tmp = cursor2->next->next;
			}
			else if (cursor1->val >= cursor2->val && cursor2->next != NULL && cursor1->val >= cursor2->next->val) {
				bigger = true;
			}
			if (!bigger) {
				cursor1 = tmp2;
			}
			cursor2 = cursor2->next;

			if(cursor1 && cursor2){
				cout << "Next val curs2  " << cursor2->val << "  next val curs1  " << cursor1->val << endl;
			}

		}
		//cursor2->next = NULL;
		return list2;
	};

};
int main()
{
	Solution a;
	ListNode list1(1);
	ListNode list2(1);
	
	ListNode nodes1[2];
	nodes1[0].val = 2;
	nodes1[0].next = &nodes1[1];
	nodes1[1].val = 4;
	nodes1[1].next = NULL;

	ListNode nodes2[2];
	nodes2[0].val = 3;
	nodes2[0].next = &nodes1[1];
	nodes2[1].val = 4;
	nodes2[1].next = NULL;

	list1.next = &nodes1[0];
	list2.next = &nodes2[0];


	ListNode* tmp = a.mergeTwoLists(&list1,&list2);
	
	while (tmp) {
		cout << tmp->val << endl;
		tmp = tmp->next;
	}
	
	
	return 0;
}
