from collections import deque

graph = {}
graph["you"] = ["alice", "bob", "claire"] 
graph["bob"] = ["anuj", "peggy"] 
graph["alice"] = ["peggy"] 
graph["claire"] = ["thom", "jonny"] 
graph["anuj"] = [] 
graph["peggy"] = [] 
graph["thom"] = [] 
graph["jonny"] = []


def person_is_seller(person):
    if person[-1] == 'm':
        return True
    else:
        return False


def search_queue():
    search_deque = deque()
    search_deque += graph["you"]
    searched_dict = {}
    while search_deque:
        person = search_deque.popleft()
        if not searched_dict.get(person):
            if person_is_seller(person):
                print "Seller is " + person
            else:
                search_deque += graph[person]
        searched_dict[person] = True

    return False



if __name__ == "__main__":
    search_queue()
