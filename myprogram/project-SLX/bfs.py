
class Node(object):
    def __init__(self,name):
        self.name = name;
        self.adjlist = [];
        self.visited = False;
        self.pred = None;
class mBFS(object):
    def bfs(self,startNode):
        queue = [];
        queue.append(startNode);
        startNode.visited = True;
        
        while queue:
            actualNode = queue.pop(0);
            print("%s " % actualNode.name);
            
            for n in actualNode.adjlist:
                if not n.visited:
                    n.visited = True;
                    queue.append(n);

node1 = Node("A");
node2 = Node("B");
node3 = Node("C");
node4 = Node("D");
node5 = Node("E");
node6 = Node("Ea");
node7 = Node("Eb");
node8 = Node("Ec");
node9 = Node("Ed");
node10 = Node("Ee");

node1.adjlist.append(node2);
node1.adjlist.append(node3);
node1.adjlist.append(node5);
node3.adjlist.append(node9);
node6.adjlist.append(node10);
node5.adjlist.append(node6);
node2.adjlist.append(node4);
node2.adjlist.append(node8);
node4.adjlist.append(node5);
node4.adjlist.append(node7);

bfs = mBFS();
bfs.bfs(node1);

