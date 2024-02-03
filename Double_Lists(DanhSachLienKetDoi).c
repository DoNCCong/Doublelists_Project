/*
	Created by Do Ngoc Chi Cong (DoNCCong)
	Youtube: https://www.youtube.com/@mindsetcoder
*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>


typedef struct {
	long long id;
	char name[20];
	long double price;
	long long numbers;
} Item;
typedef struct {
	Item item;
	struct Node* pNext;
	struct Node* pPrev;
} Node;
typedef struct {
	int n_items;
	struct Node* pHead;
	struct Node* pTail;
}List_Items;

List_Items *ds_list_items[100];
char names[100][50];
char name_list[100];
int dem=0;



Item Create_item();// Create a Item to create a Node
void Display_Item(Item items);//Display a Item
void FreeElement(Node* node_item);//Terminate a memory which contains the node when the programming end
void FreeListItem(List_Items* item);//Terminate a memory which contains the list when the programming end
Node* CopyNode(Node* item);//Copy a node.
void SwapNode(List_Items* items,Node* node1,Node* node2);//Swap two node.(Vi tri cung truoc va sau)
int GetLength(List_Items* list_items);// return the number of items in list
Node* RemoveNodeAndReturn(Node* item);//Remove a Node and return the Node
Node* GetNodeAtPosition(List_Items* list_items,int position);// return the Node at the position (1->)


//Init Function
List_Items* InitList();//Initialize a list, return NULL if the function isn't creat a list.
Node* CreateNode(Item item);//Create a Node Which contains the Item return NULL if the function don't create node
//Check Function
int IsEmptyNode(Node* node_item);//Check if a node is NULL, it will return 1 else 0
int IsEmptyList(List_Items* items);//Check if a List is NULL, it will return 1 else 0
//Insert Function
void InsertFirst(List_Items* items, Node* node_item);//Insert a Node into the top of list.
void InsertLast(List_Items* items, Node* node_item);//Insert a Node into the last of list.
void InsertAfteraNodeItem(List_Items* items,Node* node_item,int select,long long id,char name[],
						  long double price, long long Numbers);
//Delete Function
void RemoveFirst(List_Items* items);//Remove the first item.
void RemoveLast(List_Items* items);//Remove the last item.
void RemoveAfteraNodeItem(List_Items* items,int select,long long id,char name[],
						  long double price, long long Numbers);//Remove the Node behind the Node having criteria
//Search Function
Node* SearchNodeID(List_Items* items, long long id);//Search a Node in List which is the same ID 
Node* SearchNodeName(List_Items* items, char Name[]);//Search a Node in List which is the same Name 
Node* SearchNodePrice(List_Items* items, long double Price);//Search a Node in List which is the same Price 
Node* SearchNodeNumbers(List_Items* items, long long Numbers);//Search a Node in List which is the same Numbers 
Node* SearchNode(List_Items* items, int select,long long id,char name[],
				 long double price, long long Numbers);//1~id,2~name,3~price,4~Numbers
List_Items* SearchList(List_Items* items,int select,long long id,char name[],
				 long double price, long long Numbers);//Return a List which contain the items searched
//Print List Function
void PrintList(List_Items* items);//Display Items of every Node in List
void PrintListReverse(List_Items* items);//Display Reverse Items of every Node in List 
//Sort Function
void SelectionSortID(List_Items* item);
void QuickSortID(List_Items* list_item,int left,int right);//Sort by ID
//Merger 2 function
List_Items* Merger2Lists(List_Items* list_item1,List_Items* list_item2);//Combine the second list into the first list.
void demo();
void info();
short Unduplicate_String_Name(char name[]);
void Creat_List_Graphic(char name[]);
void Display_List_Graphic();
int main(){
	demo();
	return 0;
}
short Unduplicate_String_Name(char name[])
    {
            for(int i = 0; i < dem; i++)
            {
                if (strcmp(names[i],name)==0)
                {
                    printf("Don't same the name in list","Error" );
                    return 0;
                }
            }
            return 1;
    }
void info(){
	system("cls");
	printf("****Mindset&Coder****\n");
	printf("Note: I create the code which base on the thing.\n");
	printf("1. Init A List.\n");
	printf("2. Init A Node.\n");
	printf("3. Insert A Node into the head of list.\n");
	printf("4. Insert A Node into the back of list. \n");
	printf("5. Insert the Node which you create into the back of the node which you choose.\n");
	printf("6. Delete the head node of the list.\n");
	printf("7. Delete the back node of the list. \n");
	printf("8. Delete the Node which is the back of the node which you choose.\n");
	printf("9. Search the Node base on the property which you choose.\n");
	printf("10. Merger 2 lists into one list and print it. \n");
	printf("11. Display one list. \n");
	printf("12. Display the list name which you choose.\n");
	printf("13. Use Selection Sort Algorithm to sort the list by id.\n");
	printf("14. Use Quick Sort Algorithm to sort the list by id.\n");
	printf("Choose Your Number:  \n");
}
void Creat_List_Graphic(char name[]){
	if (!Unduplicate_String_Name(name)) return;
    ds_list_items[dem] = InitList();
	strcat(name,"\n");
    strcpy(names[dem],name);
    strcat(name_list,names[dem]);
    dem++;
}
void Display_List_Graphic(){
	printf("The List is existed\n");
	printf(name_list);
}
void demo(){
	int dk = 1,select=0;
	Node* pTemp = NULL;
	while(1){
		info();//in ra cac thong tin
		scanf("%d",&select);
		switch (select)
		{
		case 1:{
			char name[50];
			printf("Input the list name.\n");
			scanf("%s",&name);
			Creat_List_Graphic(name);
			fflush(stdin);
			break;
		}
		case 2:{
			printf("Input the node values.\n");
			pTemp = CreateNode(Create_item());
			break;
		}
		case 3:{
			int id;
			Display_List_Graphic();
			printf("Choose the list which you want to insert the head of the list, 'id' start from 1\n");
			scanf("%d",&id);
			InsertFirst(ds_list_items[id-1],pTemp);
			break;
		}
		case 4:{
			int id;
			Display_List_Graphic();
			printf("Choose the list which you want to insert the back of the list, 'id' start from 1\n");
			scanf("%d",&id);
			InsertLast(ds_list_items[id-1],pTemp);
			break;
		}
		case 5:{
			int id,dk,value_int;char value_chuoi[20] =""; 
			Display_List_Graphic();
			printf("Choose the list which you want to insert behind of the node, 'id' start from 1\n");
			scanf("%d",&id);
			printf("Input the values 1->4.\n");
			scanf("%d",&dk);
			printf("Input the values.\n");
			switch (dk)
			{
			case 1:{
				scanf("%d",&value_int);
				InsertAfteraNodeItem(ds_list_items[id-1],pTemp,1,value_int,"",0,0);
				break;
			}
			case 2:{
				scanf("%s",&value_chuoi);
				fflush(stdin);
				InsertAfteraNodeItem(ds_list_items[id-1],pTemp,2,0,value_chuoi,0,0);
				break;
			}
			case 3:{
				scanf("%d",&value_int);
				InsertAfteraNodeItem(ds_list_items[id-1],pTemp,3,0,"",value_int,0);
				break;
			}
			case 4:{
				scanf("%d",&value_int);
				InsertAfteraNodeItem(ds_list_items[id-1],pTemp,4,0,"",0,value_int);
				break;
			}
			default:
				break;
			}
			
			break;
		}
		case 6:{
			int id;
			Display_List_Graphic();
			printf("Choose the list which you want to delete the head of the list, 'id' start from 1\n");
			scanf("%d",&id);
			RemoveFirst(ds_list_items[id-1]);
			break;
		}
		case 7:{
			int id;
			Display_List_Graphic();
			printf("Choose the list which you want to delete the back of the list, 'id' start from 1\n");
			scanf("%d",&id);
			RemoveLast(ds_list_items[id-1]);
			break;
		}
		case 8:{
			int id,dk,value_int;char value_chuoi[20] =""; 
			Display_List_Graphic();
			printf("Choose the list which you want to delete behind of the node, 'id' start from 1\n");
			scanf("%d",&id);
			printf("Input the values 1->4.\n");
			scanf("%d",&dk);
			printf("Input the value:\n");
			switch (dk)
			{
				case 1:{
					scanf("%d",&value_int);
					RemoveAfteraNodeItem(ds_list_items[id-1],1,value_int,"",0,0);
					break;
				}
				case 2:{
					scanf("%s",&value_chuoi);
					fflush(stdin);
					RemoveAfteraNodeItem(ds_list_items[id-1],2,0,value_chuoi,0,0);
					break;
				}
				case 3:{
					scanf("%d",&value_int);
					RemoveAfteraNodeItem(ds_list_items[id-1],3,0,"",value_int,0);
					break;
				}
				case 4:{
					scanf("%d",&value_int);
					RemoveAfteraNodeItem(ds_list_items[id-1],4,0,"",0,value_int);
					break;
				}
			default:
				break;
			}
			break;
		}
		case 9:{
			int id,dk,value_int;char value_chuoi[20] =""; 
			Display_List_Graphic();
			printf("Choose the list which you want to search the node, 'id' start from 1\n");
			scanf("%d",&id);
			printf("Input the values 1->4.\n");
			scanf("%d",&dk);
			printf("Input the value:\n");
			switch (dk)
			{
			case 1:{
				scanf("%d",&value_int);
				SearchList(ds_list_items[id-1],1,value_int,"",0,0);
				break;
			}
			case 2:{
				scanf("%s",&value_chuoi);
				fflush(stdin);
				SearchList(ds_list_items[id-1],2,0,value_chuoi,0,0);
				break;
			}
			case 3:{
				scanf("%d",&value_int);
				SearchList(ds_list_items[id-1],3,0,"",value_int,0);
				break;
			}
			case 4:{
				scanf("%d",&value_int);
				SearchList(ds_list_items[id-1],4,0,"",0,value_int);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 10:{
			int id1,id2;
			Display_List_Graphic();
			printf("Merger two list, id start from 1\n");
			scanf("%d",&id1);
			scanf("%d",&id2);
			PrintList(Merger2Lists(ds_list_items[id1-1],ds_list_items[id2-1]));
			break;
		}
		case 11:{
			int id;
			Display_List_Graphic();
			printf("Display the list.\n");
			scanf("%d",&id);
			PrintList(ds_list_items[id-1]);
			break;
		}
		case 12:{
			Display_List_Graphic();
			break;
		}
		case 13:{
			int id;
			Display_List_Graphic();
			printf("Use Selection Sort Algorithm to sort the list by id.\n");
			scanf("%d",&id);
			SelectionSortID(ds_list_items[id-1]);
			break;
		}
		case 14:{
			int id;
			Display_List_Graphic();
			printf("14. Use Quick Sort Algorithm to sort the list by id.\n");
			scanf("%d",&id);
			QuickSortID(ds_list_items[id-1],1,ds_list_items[id-1]->n_items);
			break;
		}
		default:
			printf("Don't exist the value.\n");
			break;
		}

		//Day la noi thoat
		printf("If you want to exit the program, please type the 0 value. In contrast, you type the value which is not zero.");
		scanf("%d",&dk);
		if(dk==0) break;
	}
}
Item Create_item(){
	Item item;
	printf("Input ID of Item.\n");
	scanf("%lld",&item.id);
	fflush(stdin);
	printf("Input Name of Item.\n");
	fgets(item.name,sizeof(item.name),stdin);
	printf("Input Cost of Item.\n");
	scanf("%lf",&item.price);
	printf("Input a number of Items.\n");
	fflush(stdin);
	scanf("%lld",&item.numbers);
	return item;
}
void Display_Item(Item item){
	printf("Id: %lld Name: %s Cost: %.2lf ",item.id,item.name,item.price);
	printf("nItems: %lld \n",item.numbers);
}
List_Items* InitList(){
	List_Items* item = NULL;
	item=(List_Items*)malloc(sizeof(List_Items));
	item->pHead=item->pTail=NULL;
	item->n_items=0;
	return item;
}
Node* CreateNode(Item item){
	Node* node_item=(Node*)malloc(sizeof(Node));
	if(node_item==NULL) return NULL;
	node_item->pNext=NULL;
	node_item->pPrev=NULL;
	node_item->item=item;
	return node_item;
}
void FreeElement(Node* node_item){
	if(node_item!=NULL){
		free(node_item);
	}
}
void FreeListItem(List_Items* items){
	if(items!=NULL){
		if(items->pHead!=NULL){
			Node* temp = (Node*)items->pHead;
			Node* pNode = (Node*)temp->pNext;
			for(;pNode!=NULL;pNode=(Node*)pNode->pNext){
				FreeElement((Node*)items->pHead);
				items->pHead=pNode;
			}
		}
		free(items);
	}
}
int IsEmptyNode(Node* node_item){
	if(node_item==NULL) return 1;
	return 0;
}
int IsEmptyList(List_Items* items){
	if(items==NULL||(items!=NULL&&items->pHead==NULL)){
		return 1;
	}else{
		return 0;
	}
}
Node* SearchNodeID(List_Items* items, long long id){
	if(IsEmptyList(items)){
		return NULL;
	}
	Node* pNode=(Node*)items->pHead;
	for(;pNode!=NULL;pNode=(Node*)pNode->pNext){
		if((pNode->item).id==id){
			return pNode;
		}
	}
	return NULL;
}
Node* SearchNodeName(List_Items* items, char name[]){
	if(IsEmptyList(items)){
		return NULL;
	}
	Node* pNode=(Node*)items->pHead;
	for(;pNode!=NULL;pNode=(Node*)pNode->pNext){
		if(strcmp((pNode->item).name,name)==0){
			return pNode;
		}
	}
	return NULL;
}
Node* SearchNodePrice(List_Items* items, long double price){
	if(IsEmptyList(items)){
		return NULL;
	}
	Node* pNode=(Node*)items->pHead;
	for(;pNode!=NULL;pNode=(Node*)pNode->pNext){
		if((pNode->item).price==price){
			return pNode;
		}
	}
	return NULL;
}
Node* SearchNodeNumbers(List_Items* items, long long numbers){
	if(IsEmptyList(items)){
		return NULL;
	}
	Node* pNode=(Node*)items->pHead;
	for(;pNode!=NULL;pNode=(Node*)pNode->pNext){
		if((pNode->item).numbers==numbers){
			return pNode;
		}
	}
	return NULL;
}
void PrintList(List_Items* items){
	if(IsEmptyList(items)){
		printf("The list is empty, so can't display");	
		return;
	}
	Node* pNode=(Node*)items->pHead;
	for(;pNode!=NULL;pNode=(Node*)pNode->pNext){
		Display_Item(pNode->item);
	}
}
Node* CopyNode(Node* node_item){
	return CreateNode(node_item->item);
}
Node* SearchNode(List_Items* items, int select,long long id,char name[],long double price, long long Numbers){
	//1~id,2~name,3~price,4~Numbers
	switch (select)
	{
	case 1:
		return SearchNodeID(items,id);
	case 2:
		return SearchNodeName(items,name);
	case 3:
		return SearchNodePrice(items,price);
	case 4: 
		return SearchNodeNumbers(items,Numbers);
	default:
		return NULL;
		break;
	}
}
List_Items* SearchList(List_Items* items,int select,long long id,char name[],long double price, long long Numbers){
	List_Items* list_temp = InitList();
	if(list_temp==NULL) return NULL;
	Node* p = items->pHead;
	for(;p!=NULL;p=p->pNext){
		//do something
		if((select==1&&(p->item).id==id)||(select==2&&(p->item).name==name)||(select==3&&(p->item).price==price)||(select==4&&(p->item).numbers==Numbers)){
			if(list_temp->pHead==NULL){
				InsertFirst(list_temp,CopyNode(p));
			}else{
				InsertLast(list_temp,CopyNode(p));
			}
		}
	}
	return list_temp;
}
void InsertFirst(List_Items* items, Node* node_item){
	if(items==NULL||node_item==NULL) return;
	if(items->pHead==items->pTail&&items->pHead==NULL){
		items->pTail=(Node*)node_item;
	}
	//pRev
	node_item->pPrev=NULL;
	Node* temp = items->pHead;
	if(temp!=NULL){
		temp->pPrev=node_item;
	}
	//pNext
	node_item->pNext=(Node*)temp;
	items->pHead=(Node*)node_item;
	items->n_items+=1;
}
void InsertLast(List_Items* items, Node* node_item){
	if(items==NULL||node_item==NULL) return;
	if(items->pHead==items->pTail&&items->pHead==NULL){
		InsertFirst(items,node_item);
		return;
	}
	//pRev
	node_item->pPrev=items->pTail;
	//pNext
	node_item->pNext=NULL;
	Node* temp = items->pTail;
	temp->pNext=node_item;
	items->pTail=node_item;
	items->n_items+=1;
}
void InsertAfteraNodeItem(List_Items* items,Node* node_item,int select,long long id,char name[],long double price, long long Numbers){
	Node* temp = SearchNode(items,select,id,name,price,Numbers);
	if(temp==NULL){
		printf("Can't find the Node to insert behind it");
		return;
	}
	if(temp==items->pTail){
		InsertLast(items,node_item);
	}else{
		//do something to insert.
		items->n_items+=1;
		node_item->pNext=(Node*)temp->pNext;
		node_item->pPrev=(Node*)temp;
		Node* temp2 = (Node*)temp->pNext;
		temp2->pPrev=(Node*)node_item;
		temp->pNext=(Node*)node_item;
	}
}
void RemoveFirst(List_Items* items){
	if(items==NULL || items->pHead==NULL){
		return ;
	}
	if(items->pHead==items->pTail){
		items->pTail=NULL;
	}
	Node* temp = items->pHead;
	items->pHead=(Node*)temp->pNext;
	if(temp!=NULL){
		FreeElement(temp);
	}
	items->n_items-=1;
}
void RemoveLast(List_Items* items){
	if(items==NULL || items->pHead==NULL){
		return ;
	}
	if(items->pHead==items->pTail){
		items->pHead=NULL;
	}
	Node* temp = (Node*)items->pTail;
	items->pTail=(Node*)temp->pPrev;
	Node* temp1=items->pTail;
	temp1->pNext=NULL;
	if(temp!=NULL){
		FreeElement(temp);
	}
	items->n_items-=1;
}
void RemoveAfteraNodeItem(List_Items* items,int select,long long id,char name[],long double price, long long Numbers){
	Node* temp = SearchNode(items,select,id,name,price,Numbers);
	if(temp==NULL){
		printf("Can't find the Node to insert behind it");
	}
	if(temp==items->pTail){
		RemoveLast(items);
	}else{
		items->n_items-=1;
		Node* temp2 = (Node*)temp->pNext;
		temp->pNext=(Node*)temp2->pNext;
		Node* temp3 = temp2->pNext;
		temp3->pPrev=temp;
		FreeElement(temp2);
	}
}
void SwapNode(List_Items* list_items,Node* node1,Node* node2){
	if(node1==node2) return;
	if(node1==NULL||node2==NULL){
		return;
	}
	if(node2->pNext==NULL){
		list_items->pTail=node1;
	}
	if(node1->pPrev==NULL){
		list_items->pHead=node2;
	}
	Node* tempPrev1 = (Node*)node1->pPrev;
	Node* tempNext1 = (Node*)node1->pNext;
	Node* tempPrev2 = (Node*)node2->pPrev;
	Node* tempNext2 = (Node*)node2->pNext;
	//Danh cho truong hop chay tien
	if(tempPrev1!=NULL){
		tempPrev1->pNext=node2;
	}
	if(tempNext1!=node2){
		node2->pNext=tempNext1;
	}else{
		node2->pNext=node1;
	}
	if(tempPrev2!=NULL){
		tempPrev2->pNext=node1;
	}
	node1->pNext=tempNext2;
	//Danh cho truong hop chay luoi
	if(tempNext2!=NULL){
		tempNext2->pPrev=node1;
	}
	if(tempPrev2!=node1){
		node1->pPrev=tempPrev2;
	}else{
		node1->pPrev=node2;
	}
	if(tempNext1!=NULL){
		tempNext1->pPrev=node2;
	}
	node2->pPrev=tempPrev1;
}
void PrintListReverse(List_Items* items){
	if(IsEmptyList(items)){
		printf("The list is empty, so can't display");	
		return;
	}
	Node* pNode=(Node*)items->pTail;
	for(;pNode!=NULL;pNode=(Node*)pNode->pPrev){
		Display_Item(pNode->item);
	}
}
void SelectionSortID(List_Items* items){
	Node* node_i;
	int dem=0;
	for(node_i=items->pTail;node_i!=NULL;node_i=node_i->pPrev){
		Node* max=node_i;
		Node* node_j=items->pHead;
		for(;node_j!=node_i;node_j=node_j->pNext){
			if((node_j->item).id>(max->item).id){
				max=node_j;
			}
		}
		if(max!=node_i){
			SwapNode(items,max,node_i);
			node_i=max;//Cap nhat lai gia tri node
		}
	}
}
int GetLength(List_Items* list_items){
	if(list_items==NULL) return 0;
	return list_items->n_items;
}
Node* GetNodeAtPosition(List_Items* list_items,int position){//tinh tu 1
	if(list_items==NULL) return NULL;
	Node* pNode = list_items->pHead;
	int dem = 1;
	while (dem!=position&&pNode!=NULL)
	{
		pNode=pNode->pNext;
		dem++;
	}
	return pNode;
}
void QuickSortID(List_Items* list_item,int left,int right){//Bat dau nhat la tu 1 den n
	//dosomething
	if(left>=right) return;
	if((left+1)==right){
		Node* node1 = GetNodeAtPosition(list_item,left);
		Node* node2 = GetNodeAtPosition(list_item,right);
		if((node1->item).id>(node2->item).id){
			SwapNode(list_item,node1,node2);
		}
		return;
	}
	int mid = ceil((double)(left+right)/2),index_min,index_max,flag_min,flag_max;
	int sl_min=0,sl_max=0;
	Node* node_start = GetNodeAtPosition(list_item,left);//Lay vi tri node bat dau.
	if(node_start==NULL) return;
	Node* node_end = GetNodeAtPosition(list_item,right);
	Node* pNode_mid = GetNodeAtPosition(list_item,mid);
	Node* pTemp = node_start;
	//dem so luong phan tu nho hon va lon hon hien tai.
	while (pTemp!=NULL&&pTemp!=node_end->pNext)
	{
		if(pTemp!=pNode_mid&&(pTemp->item).id<=(pNode_mid->item).id){
			sl_min+=1;
		}
		pTemp=pTemp->pNext;
	}
	sl_max=(right-left)-sl_min;
	//Dung ham hoan doi neu co the
	Node * node_pos = GetNodeAtPosition(list_item,left+sl_min);
	if(left+sl_min < mid){
		SwapNode(list_item,node_pos,pNode_mid);
	}else{
		SwapNode(list_item,pNode_mid,node_pos);
	}
	mid = left+sl_min;
	index_min=left;index_max=left+sl_min+1;//Luu vi tri de swap
	//ThuatToanChuyenChinh
	pTemp = node_start;
	Node* pTemp_mid = pNode_mid->pNext;
	flag_min=0;flag_max=0;//Xet cac truong hop dac biet
	Node* node1; Node* node2;//Khong dat hai con tro cung chung trong c se bi loi
	while (pTemp!=NULL&&pTemp!=pNode_mid)//Cho chay den phan tu giua
	{
		if((pTemp->item).id>(pNode_mid->item).id){
			node1 = pTemp;
			pTemp = pTemp->pNext;
			while (pTemp_mid!=NULL&&pTemp_mid!=(node_end->pNext))
			{
				if((pTemp_mid->item).id<=(pNode_mid->item).id) break;
				pTemp_mid = pTemp_mid->pNext;
			}
			node2 = pTemp_mid;
			pTemp_mid = pTemp_mid->pNext;
			SwapNode(list_item,node1,node2);
		}else
			pTemp=pTemp->pNext;
	}
	QuickSortID(list_item,left,mid-1);
	QuickSortID(list_item,mid+1,right);
}
List_Items* Merger2Lists(List_Items* list_item1,List_Items* list_item2){
	List_Items* merger_list = InitList();
	if (list_item1 == NULL && list_item2 == NULL) return;
            if(list_item1 == NULL)
            {
                Node* pTemp = list_item2->pHead;
                for (; pTemp != NULL;pTemp=pTemp->pNext)
                {
                    InsertLast(merger_list,CopyNode(pTemp));
                }
                
                return;
            }
            if (list_item2 == NULL)
            {
                Node* pTemp = list_item1->pHead;
                for (; pTemp != NULL;pTemp=pTemp->pNext)
                {
                    InsertLast(merger_list,CopyNode(pTemp));
                }
                return;
            }

  
            Node* pTemp1 = list_item1->pHead;
            for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext)
            {
                InsertLast(merger_list,CopyNode(pTemp1));
            }
            
            Node* pTemp2 = list_item2->pHead;
            
           
            for (; pTemp2 != NULL; pTemp2 = pTemp2->pNext)
            {
                InsertLast(merger_list,CopyNode(pTemp2));
            }
	return merger_list;
}
