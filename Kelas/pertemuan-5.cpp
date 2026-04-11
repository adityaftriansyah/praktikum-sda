void transversal(Node head) {
if (head == NULL) {
cout << "Linked list kosong" << endl;
return;
}
Node temp = head;
while (temp != NULL) {
cout << temp->data << " -> ";
temp = temp->next;
}
cout << "NULL" << endl;
}
