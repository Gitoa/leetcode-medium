ListNode* Merge(ListNode* l, ListNode* r){
	if(l==NULL){
		return r;
	}
	if(r==NULL){
		return l;
	}
	ListNode *h , *p;
	if(l->val < r->val){
		h = l;
		l = l->next;
	}else{
		h = r;
		r = r->next;
	}
	p = h;
	while(l != NULL && r !=NULL){
		if(l->val<r->val){
			p->next = l;
			l = l->next;
		}else{
			p->next = r;
			r = r->next;
		}
		p = p->next;
	}
	if(l != NULL){
		p->next = l;
	}else if(r != NULL){
		p->next = r;
	}
	return h;
}

ListNode* sortList(ListNode* head){
	if(head == NULL || head->next == NULL){
		return head;
	}else{
		ListNode *fast = head, *slow = head;
		while(fast->next != NULL && fast->next->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		fast = sortList(head);
		slow = sortList(slow);
		return Merge(fast, flow);
	}
}