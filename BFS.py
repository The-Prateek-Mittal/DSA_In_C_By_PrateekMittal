import queueclass 

graph = { 
    'r' : ['s','t','w'], 's': ['r','u','v'],
    't': ['r','u'], 'u': ['s','t','y'],
    'v' : ['s','w','y'], 'w': ['r','v','x','z'],
    'x' : ['w','y','z'], 'y': ['u','v','x'],
    'z' : ['w','x']
}

def BFS(graph,source):
    vertex_attribute = {v : {'colour':'WHITE', 'distance': 'None','parent': 'None'} for v in graph}
    vertex_attribue[source]['colour'] = 'GRAY'
    vertex_attribue[source]['distance'] = 0
    vertex_attribue[source]['parent'] = None
    
    Q = queueclass.Queue()
    Q.ENQUEUE(source)

    while(Q.notempty()):
        u = Q.DEQUEUE()
        
        for v in graph[u]:
            if vertex_attribue[v]['colour'] == 'WHITE':
                vertex_attribue[v]['colour'] = 'GRAY'
                vertex_attribue[v]['distance'] = 0
                vertex_attribue[v]['parent'] = u 
                
                Q.ENQUEUE(v)
        
        vertex_attribue[u]['colour'] = 'BLACK'
        
        vertex_attribue[source]['colour'] = 'GRAY'

    return vertex_attribute


if __name__ == '__main__':
    
    vertex_attribue = BFS(graph,'s')
    
    for key, value in vertex_attribue.items():
        print(f"{key}:{value}")
        
    
    
    