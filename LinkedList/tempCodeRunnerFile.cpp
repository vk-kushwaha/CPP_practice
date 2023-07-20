class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void addAtTail(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else
    {

        node *newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}
