'''
this file is used to find the lowest cost route
'''

graph = {}
graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2
graph["a"] = {}
graph["a"]["fin"] = 1
graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["fin"] = 5
graph["fin"] = {}

infinity = float("inf") 
costs = {} 
costs["a"] = 6 
costs["b"] = 2 
costs["fin"] = infinity

parents = {} 
parents["a"] = "start" 
parents["b"] = "start" 
parents["fin"] = None

processed = []

def find_lowest_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node


def print_route(path):
    start_point = "start"
    end_point = "fin"
    search_point = start_point
    lowest_cost_path = []
    lowest_cost_path.append("start")
    while search_point != end_point:
        for node in parents:
            if parents[node] == search_point:
                lowest_cost_path.append(node)
                search_point = node
    print lowest_cost_path

if __name__ == "__main__":
    print graph
    node = find_lowest_cost_node(costs)
    while node is not None:
        cost = costs[node]
        neighbors = graph[node]
        for n in neighbors.keys():
            new_cost = cost + neighbors[n]
            if costs[n] > new_cost:
                costs[n] = new_cost
                parents[n] = node
        processed.append(node)
        node = find_lowest_cost_node(costs)
    print parents
    print "lowest cost path"
    print_route(parents)
