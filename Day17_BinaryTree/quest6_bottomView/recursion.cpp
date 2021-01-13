/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */
int r=0,l=0;
void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
      
    // If node for a particular  
    // horizontal distance is not 
    // present, add to the map. 
    if (m.find(hd) == m.end())  
    { 
        m[hd] = make_pair(root -> data, curr); 
    }  
    // Compare height for already  
    // present node at similar horizontal 
    // distance 
    else 
    { 
        pair < int, int > p = m[hd]; 
        if (p.second <= curr) 
        { 
            m[hd].second = curr; 
            m[hd].first = root -> data; 
        } 
    } 
      
    // Recur for left subtree 
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m); 
      
    // Recur for right subtree 
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m); 
} 


vector <int> bottomView(Node *root)
{
   // Your Code Here
   vector<int> v;
   // Map to store Horizontal Distance, 
    // Height and Data. 
    map < int, pair < int, int > > m; 
      
    printBottomViewUtil(root, 0, 0, m); 
      
     // Prints the values stored by printBottomViewUtil() 
    map < int, pair < int, int > > ::iterator it; 
    for (it = m.begin(); it != m.end(); ++it) 
    { 
        pair < int, int > p = it -> second; 
        v.push_back(p.first); 
    } 
   return v;
}
