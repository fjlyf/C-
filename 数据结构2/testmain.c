
#include"list.h"

void Test_List()
{
	List mylist;      //ListNode *mylist
	ListInit(&mylist);
	/*ListCreate_Tail(&mylist);*/
	ListCreate_Head(&mylist);
	ListShow(mylist);

}

void main()
{
	Test_List();
}

/*
int main()
{
	SeqList mylist;
	SeqListInit(&mylist);

	ElemType item,key;
	int select = 1;
	int pos = 0;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back           [2] push_front   *\n");
		printf("* [3] show_list           [0] quit_system  *\n");
		printf("* [4] pop_back            [5] pop_front    *\n");
		printf("* [6] insert_pos          [6] insert_val   *\n");
		printf("* [8] delete_pos          [9] delete_val   *\n");
		printf("* [10] find_val           [11] length      *\n");
		printf("* [12] capacity           [13] sort        *\n");
		printf("* [14] reverse            [15] clear       *\n");
		printf("* [16] remove_all                          *\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d",&select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置;>");
			scanf("%d",&pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertPos(&mylist, pos, item);
			break;
		case 7:
			SeqListButterSort(&mylist);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListDeletePos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SeqListDelectVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos=SeqListFindVal(&mylist,key);
			if (pos == -1)
				printf("要查找的值不存在\n");
			else
				printf("查找的值的位置为:>%d\n",pos);
			break;
		case 11:
			printf("seqlist len=%d\n", SeqListLength(&mylist));
			break;
		case 12:
			printf("seqlist Capa=%d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SeqListButterSort(&mylist);
			printf("顺序表排序成功!........\n");
			break;
		case 14:
			SeqListReverse(&mylist);
			break;
		case 15:
			SeqListClear(&mylist);
			printf("顺序表清除成功!.......\n");
			break;
		}
	}
	printf("GoodBye.......\n");
	SeqListDestroy(&mylist);
	return 0;
}*/