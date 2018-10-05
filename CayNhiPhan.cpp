#include <D:\lib\bstlib.h>

int main(){
	TNode *bst;
	bst = Create2(27,
	Create2(12,
		Create2(4,NULL,NULL),
		Create2(20,NULL,NULL)
	),
	Create2(40,
		Create2(34,
			Create2(30,NULL,NULL),NULL
		),
		Create2(50,NULL,NULL)
	)
);
	InOrder(bst);
}
