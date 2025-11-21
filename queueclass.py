class Queue():
    def __str__(self):
        return("Queue Using List")
    
    #Constructor
    def __init__(self):
        self.Q = []
        
    def ENQUEUE(self, item):
        self.Q.append(item)
    
    def DEQUEUE(self):
        return(self.Q.pop(0))
    
    def printQ(self):
        for idx, item in enumerate(self.Q):
            print(idx , item)
            
    def notempty(self):
        return(len(self.Q))
    

if __name__ == '__main__':
    
    gQ = Queue()
    print(gQ) 
    
    gQ.ENQUEUE(11)
    gQ.ENQUEUE(22)
    gQ.ENQUEUE(33)
    
    gQ.printQ()
    
    x = gQ.DEQUEUE()
    print(f"Value {x} deleted from the queue.")
    
    gQ.printQ()

    