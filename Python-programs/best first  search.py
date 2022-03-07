def best_first_search(graph, goal, starting):
    open = {}
    closed = [starting]
    print()
    print(graph)
    if goal not in graph:
        print("wrong node entered")
        return
    node = starting  # current node
    while True:
        neighbours = graph[node]
        open = {**neighbours,**open}
        sorted_open = dict(sorted(open.items(), key=lambda x: x[1]))
        first_key_value = list(sorted_open.items())[0]
        if goal == first_key_value[0]:
            closed.append(first_key_value[0])
            print("Goal node found")
            print("Traversal Order : "+''.join([str(elem) for elem in closed]))
            return
        open.pop(first_key_value[0])
        closed.append(first_key_value[0])
        node = first_key_value[0]


n = int(input("enter number of nodes : "))
graph = {}
subgraph = {}
for i in range(n):
    key = input("enter the node : ")
    # child_count = int(input("enter number of child nodes : "))
    child_count = 10
    for x in range(child_count):
        child = input("enter the child node : ")
        if child == "":
            break
        child_value = int(input("enter the value of " + child + " : "))
        subgraph[child] = child_value
    graph[key] = subgraph
    subgraph = {}
    print("")
starting_node = input("enter the root node : ")
goal_node = input("enter goal node : ")
best_first_search(graph, goal_node, starting_node,)
