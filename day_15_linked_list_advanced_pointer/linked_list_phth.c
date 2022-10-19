/* https://www.thegeekstuff.com/2012/08/c-linked-list-example/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// a block/node in a linked list
struct test_struct
{
    int val;
    struct test_struct *next;
};

// The "head" pointer always points to the first node.
// If the entire list is empty (contains no nodes), the head pointer is set to NULL
struct test_struct *head = NULL;
// Similarly there is a "curr" pointer that points to the last node in the list.
// Since "curr" points to the last node, curr->next must always be NULL!
struct test_struct *curr = NULL;

struct test_struct* create_list(int val)
{
    printf("\n creating list with headnode as [%d]\n",val);
    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

struct test_struct* add_to_list(int val, bool add_to_end)
{
    // Whenever a node is added to linked list, it is always checked if the linked list is empty
    if(NULL == head)
    {
        return (create_list(val));
    }

    if(add_to_end)
        printf("\n Adding node to end of list with value [%d]\n",val);
    else
        printf("\n Adding node to beginning of list with value [%d]\n",val);

    // Create a node (of type test_struct) (which involves 1.-3.):
    // 1. allocate memory for the new node (ptr points to this node and lets us access the node's elements)
    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    // 2. assign the val passed to add_to_list() to the new node's member variable val
    ptr->val = val;
    // 3. The node's next pointer is assigned the address of the next node. If no next node exists (or if its the last node) a NULL is assigned.
    ptr->next = NULL;

    // add the created node to the list
    if(add_to_end)
    {
        // add to the end of the list
        curr->next = ptr;
        curr = ptr;
    }
    else
    {
        // add to the beginning of the list
        ptr->next = head;
        head = ptr;
    }
    return ptr;
}

/**
 * @brief Search the list for a specific element.
 * 
 * @param val the value of the node to be found
 * @param prev a pointer to the node previous to the found node
 * @return struct test_struct* pointer to the found element or NULL, if not found
 */
struct test_struct* search_in_list(int val, struct test_struct **prev)      // *prev (nicht prev !) is "passed by reference using pointers", d.h. 
                                                                            // wir können das original *prev aus delete_from_list hier 
                                                                            // in search_in_list ändern und die Änderung bleibt nach
                                                                            // Rückkehr zu delete_from_list erhalten! (s. "passing_by_reference.c")
{
    struct test_struct *ptr = head;
    struct test_struct *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n",val);

    // traverse the linked list to match the node containing "val"
    while(ptr != NULL)
    {
        if(ptr->val == val)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;          // we need tmp to be able to return the previous node in the following
            ptr = ptr->next;
        }
    }

    // return a pointer to the found node
    if(true == found)
    {
        if(prev)
            *prev = tmp;        // also return the previous node, if there is one
        return ptr;
    }
    else
    {
        return NULL;
    }
}

/**
 * @brief deletes a node in the linked list
 * 
 * @param val the value of the node being deleted
 * @return int 0, if deletion was successful; -1, if node with value "val" not found.
 */
int delete_from_list(int val)
{
    struct test_struct *prev = NULL;    // pointer to the adjacent node before the node being deleted (thus, NULL for head node)
    struct test_struct *del = NULL;     // node being deleted

    printf("\n Deleting value [%d] from list\n",val);

    del = search_in_list(val,&prev);    // "&prev" als argument heißt "prev" ist ein "zweiter return Wert" von search_in_list() (vgl. passing_by_reference.c)
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)                // when deleting any node except the first node
            prev->next = del->next;     // set the next pointer of the element before the one being deleted to point to the element after the one being deleted

        // "[...] there is a "curr" pointer that contains the LAST NODE in the list. This is also adjusted when last node is deleted."
        if(del == curr)
        {
            curr = prev;                // delete last node
        }
        // "The FIRST NODE is always made accessible through a global "head" pointer. This pointer is adjusted when first node is deleted."
        else if(del == head)
        {
            head = del->next;           // delete first node
        }
    }

    free(del);
    del = NULL;

    return 0;
}

void print_list(void)
{
    struct test_struct *ptr = head;

    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf(" [%d]",ptr->val);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}

int main(void)
{
    int i = 0, ret = 0;
    struct test_struct *ptr = NULL;

    print_list();

    for(i = 5; i<10; i++)
        add_to_list(i,true);    // add to the end of the list

    print_list();

    for(i = 4; i>0; i--)
        add_to_list(i,false);   // add to the beginning of the list

    print_list();

    for(i = 1; i<10; i += 4)
    {
        ptr = search_in_list(i, NULL);
        if(NULL == ptr)
        {
            printf("\n Search [val = %d] failed, no such element found\n",i);
        }
        else
        {
            printf("\n Search passed [val = %d]\n",ptr->val);
        }

        print_list();

        ret = delete_from_list(i);
        if(ret != 0)
        {
            printf("\n delete [val = %d] failed, no such element found\n",i);
        }
        else
        {
            printf("\n delete [val = %d] passed \n",i);
        }

        print_list();
    }

    return 0;
}