//
//  main.cpp
//  Project5
//
//  Created by Feras Salous  on 4/19/19.
//  Copyright © 2019 Feras Salous . All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
template <class DT>
class LinkedList {
protected:
    DT* data; // what kind of data you are putting in the list
    LinkedList<DT>* _next;// points to the next node in the list.
    int lengthOfLinkedList;// counter to hold my number of elements in linkedlist.
    LinkedList<DT>* _start; //points to the head node, or the first element in the list.
public:
    LinkedList();
    LinkedList(DT& _data, LinkedList<DT>* _next);
    LinkedList(DT& _data);
    ~LinkedList();
    void insertItem(DT& item); // insert an item
    void removeAt(int index); // removes an element at a specified index.
    int size(); // returns  the size in my list.
    DT& infoAt(int pos);
    void add(DT& x);
    void getNext();
    DT& operator[](int index);
    LinkedList(const LinkedList<DT>&x);
    void insertAt(int index, DT&x);
    void remove();
    int getLength();
};
//empty constructor
template<class DT>
LinkedList<DT>::LinkedList()
{
    _next = NULL; // points to the next in the list
    data = NULL;// holds some data value
    _start = NULL; // points to the current node.
    lengthOfLinkedList = 1; //length of my list
}
//This constructor takes in a data type and a linkedlist pointing to the next node.
template <class DT>
LinkedList<DT>::LinkedList(DT& _data, LinkedList<DT>* next)
{
    data = new DT(_data);
    _next = next;
}
// this constructor only takes in a data type
template <class DT>
LinkedList<DT>::LinkedList(DT& _data)
{
    data = new DT(_data);
    _next = NULL;
}
// This is my destructor.
template <class DT>
LinkedList<DT>::~LinkedList<DT>()
{
    if(data != NULL)
    {
        delete data;
        data = NULL;
    }
    if(_next != NULL)
    {
        delete _next;
        _next = NULL;
    }
}
//This is is my add method, which takes in a data type and inserts it into my linked list.
template<class DT>
void LinkedList<DT>::add(DT& x)
{
    //if the data is null create a new data object of that specified type
    if(data == NULL)
    {
        data = new DT(x);
        // ++lengthOfLinkedList;
    }
    // else create a temp list and store it into that.
    else
    {
        
        LinkedList<DT>* temp = new LinkedList(*data,_next);
        *data = x;
        _next = temp;
        lengthOfLinkedList++;
        
    }
    
}
template <class DT>
int LinkedList<DT>::getLength()
{
    return  lengthOfLinkedList;
}
/// this returns info at a specific postion from the linked list. A recursice method.
template<class DT>
DT& LinkedList<DT>::infoAt(int pos)
{
    if(pos == 0)
    {
        return *data;
    }
    return _next -> infoAt(pos-1);
}
/*
 This method returns the size of the linked list: O(1)
 */
template <class DT>
int LinkedList<DT>::size() {
    if(_next == NULL)
    {
        if(data == NULL )return 0;
        else return 1;
    }
    else return (1 + _next->size());
}
/*
 This method inserts an item into the list of any DataType. Temp is a temp pointer which will point to start.
 Temp will also 'store' the item given. Temp will then point to start which is Null. _start then will point temp which is the currentNode persay.
 */
template <class DT>
void LinkedList<DT>::insertItem(DT& item) {
    LinkedList<DT>* temp = new LinkedList;
    data  = &item;
    temp -> _next = _start;
    _start  = temp;
    ++lengthOfLinkedList;
    
}
//inserts an item at a specified postion.
template <class DT>
void LinkedList<DT>::insertAt(int index, DT &x)
{
    if(index == 0)
        
    {
        add(x);
    }
    else
    {
        if(_next == NULL)
        {
            _next = new LinkedList<DT>(x);
        }
        
        else
        {
            (*_next).insertAt(index - 1, x);
        }
    }
}
template<class DT>
void LinkedList<DT>::remove()
{
    if(data != NULL)
    {
        delete data;
        LinkedList<DT>* temp = _next;
        data = temp -> data;
        _next = temp -> _next;
        temp -> data = NULL;
        temp -> _next = NULL;
        delete temp;
    }
    
}
//Removes an element at a specified index.
template <class DT>
void LinkedList<DT>::removeAt(int index) {
    if(index == 0)
    {
        remove();
    }
    else{
        _next -> removeAt(index -1);
    }
    
    
    
    
}
//Overloaded [] operator which returns the element at [ith] element in the linkedlist.
//template <class DT>
//DT& LinkedList<DT>::operator[](int index)
//{
//    return infoAt(index);
//}
// copy construcor.
template <class DT>
LinkedList<DT>::LinkedList(const LinkedList<DT>&x)
{
    if( x.data == NULL)
    {
        data = NULL;
    }
    else
    {
        data = x.data;
    }
    if(x._next == NULL)
    {
        _next = NULL;
    }
    else{
        _next = x._next;
    }
}
// just a method to get my next element.
template <class DT>
void LinkedList<DT>::getNext()
{
    return _next;
}
class GraphAdjacenyMatrix
{
protected:
    int** adjacencyMatrix;
    int numberOfNodes;
public:
    GraphAdjacenyMatrix();
    GraphAdjacenyMatrix(int numberOfNodes);
    ~GraphAdjacenyMatrix();
    GraphAdjacenyMatrix(const GraphAdjacenyMatrix& x);
    GraphAdjacenyMatrix operator = (const GraphAdjacenyMatrix&x);
    void addEdge(int start, int finish);
    void displayGraph();
    void BFS(GraphAdjacenyMatrix& x, int vertices);
    friend ostream& operator << (ostream& s, const GraphAdjacenyMatrix& x);
};
GraphAdjacenyMatrix:: GraphAdjacenyMatrix()
{
}
GraphAdjacenyMatrix::GraphAdjacenyMatrix(int numberOfVertcies)
{
    //cout << "entered here";
    numberOfNodes = numberOfVertcies;
    adjacencyMatrix = new int* [numberOfNodes];
    for(int i = 0; i < numberOfNodes; ++i)
    {
        adjacencyMatrix[i] = new int[numberOfNodes];
        for (int j = 0; j < numberOfNodes; ++j) {
            adjacencyMatrix[i][j] =0;
        }
    }
    
}
GraphAdjacenyMatrix:: GraphAdjacenyMatrix(const GraphAdjacenyMatrix&x)
{
    numberOfNodes = x.numberOfNodes;
    adjacencyMatrix = x.adjacencyMatrix;
    
}
void GraphAdjacenyMatrix::addEdge(int start, int finish)
{
    // cout << "Entred here";
    adjacencyMatrix[start][finish] = 1;
    adjacencyMatrix[finish][start] =1;
    
}
void GraphAdjacenyMatrix::displayGraph()
{
    for (int i = 0; i < numberOfNodes; ++i) {
        for (int j = 0; j < numberOfNodes; ++j) {
            if (adjacencyMatrix[i][j] == 1 && i > j) {
                cout << j << " " << i <<endl;
            }
        }
    }
    for (int i = 0; i < numberOfNodes; ++i) {
        for (int j = 0; j < numberOfNodes; ++j) {
            cout<< adjacencyMatrix[i][j] << "  ";
        }
        cout << endl;
    }
}
void GraphAdjacenyMatrix::BFS(GraphAdjacenyMatrix &x, int vertex)
{
    int vistedArray[numberOfNodes]; // to see the nodes i have visited and check them
    queue<int>* myElements = new queue<int>();
    int *parents = new int[numberOfNodes];
    int count = 0;
    for(int i =0; i < numberOfNodes; ++i) // set all elements in the visted array equal to 0. 0 is for unvisted. 1 is for visited.
    {
        vistedArray[i] = 0;
    }
    vistedArray[vertex] = 1; // visted at the vertex will equal one to signify we have check it.
    myElements -> push(vertex); // push it in the queue
    cout << vertex << ":-1" << endl;// print it.
    while (!(myElements -> empty())) {  // while my queue is not empty.
        int deQueues = myElements -> front();// my first element in the queue
        myElements -> pop();// remeove it
        for(int j =0; j < numberOfNodes; ++j)
        {
            if(vistedArray[j] == 0 && x.adjacencyMatrix[deQueues][j] == 1)
            {
                parents[j] = deQueues;
                // cout << "These are the deQueue values"<< " " << deQueues << endl;
                // cout << "These are the parents" << parents[j] << endl;
                vistedArray[j] = 1;
                myElements -> push(j);
                cout << deQueues << ":" << j << endl;
                ++ count;
            }
        }
    }
}
GraphAdjacenyMatrix GraphAdjacenyMatrix::operator=(const GraphAdjacenyMatrix &x)
{
    adjacencyMatrix = x.adjacencyMatrix;
    numberOfNodes = x.numberOfNodes;
    return *this;
}
ostream& operator <<(ostream& s, const GraphAdjacenyMatrix& x)
{
    cout << x.numberOfNodes << endl;
    for (int i = 0; i < x.numberOfNodes; ++i) {
        for (int j = 0; j < x.numberOfNodes; ++j) {
            if (i > j && x.adjacencyMatrix[i][j] == 1) {
                s << j << " " << i << endl;
            }
        }
    }
    return s;
    
}
// --------------------------//
class GraphLinkedList
{
protected:
    LinkedList<int>*myGraph;
    int sizeOfGraph;
public:
    
    GraphLinkedList();
    GraphLinkedList(int nodes);
    GraphLinkedList(const GraphLinkedList& x);
    void addEdge(int start,int finish);
    void display();
    void BFS(GraphLinkedList&x , int vertex);
    int sizeOfList;
};
GraphLinkedList::GraphLinkedList(int nodes)
{
    myGraph = new LinkedList<int>[nodes];
    sizeOfGraph = nodes;
    sizeOfList = 0;
}
void GraphLinkedList::addEdge(int start, int finish)
{
    myGraph[start].add(finish);
    myGraph[finish].add(start);
    sizeOfList++;
}
GraphLinkedList::GraphLinkedList(const GraphLinkedList& x)
{
    sizeOfGraph = x.sizeOfGraph;
    myGraph = x.myGraph;
}
void GraphLinkedList::display()
{
    for (int i = 0; i < sizeOfGraph; i++) {
      if(myGraph[i].size() > 0)
      {
          cout << i << " ";
          for (int j = 0; j < myGraph[i].size(); ++j) {
              cout << myGraph[i].infoAt(j) << " " << i;
          }
          cout << endl;
      }
       
    }
}
void GraphLinkedList::BFS(GraphLinkedList &x, int vertex)
{
    queue<int>* myElements = new queue<int>();
    int vistedArray[sizeOfGraph];
    for (int i = 0; i < sizeOfGraph; i++)
    {
        vistedArray[i] =0;
    }
    vistedArray[vertex] = 1;
    myElements -> push(vertex);
    cout << vertex << ":-1" << endl;
    while (!myElements -> empty()) {
        int deQueue = myElements -> front();
        //cout << "these are the dequuees:" << deQueue << endl;
        myElements -> pop();
        for(int i =0; i < x.myGraph[deQueue].size(); ++i)
        {
            //cout << "This is the size" << x.myGraph[deQueue].size() << endl;
            int neighbors = myGraph[deQueue].infoAt(i);
            if(!(vistedArray[neighbors]))
            {
                vistedArray[neighbors] = 1;
                cout << deQueue << ":" << myGraph[deQueue].infoAt(i) << endl;
                myElements -> push(neighbors);
            }
        }
    }
}
int main() {
    int vertex,edge,nodes;
    cin >> nodes;
    GraphAdjacenyMatrix *x = new GraphAdjacenyMatrix(nodes);
    GraphAdjacenyMatrix *z = new GraphAdjacenyMatrix(nodes);
    GraphLinkedList *y = new GraphLinkedList(nodes);
    for(int i =0; i < nodes; ++i)
    {
        cin >> vertex >> edge;
        x -> addEdge(vertex, edge);
        y -> addEdge(vertex, edge);
        
    }
    //DISPLAY METHODS
    cout <<"This is X"<< endl;  cout << *x << endl;
    //y -> display();
    
    // OVERLOAD = OPERATOR
    z = x;
    cout << "This is Overload = Of Adjacency Matrix"<< endl;
    cout<< *z;
    cout << endl;
    
    //COPY CONSTRUCTOR
    GraphAdjacenyMatrix * copy(x);
    cout << "This is the Copy Of Adjacency Matrix" << endl;
    cout << *copy;
    
    //BFS
    cout << "BFS on Adjacency list" << endl; y -> BFS(*y, 0);
    cout << "BFS for Adjacency Matrix: " << endl; x -> BFS(*x, 0);
    return 0;
}

