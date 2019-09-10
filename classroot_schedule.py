'''
This file is demonstrate how to use General Greed algorithm to solve classroom schedule problem.The task is to select courseed you can attend the more the better.

english 9 10
math    9 11
cs      10 12
music   12 14
art     13 15
program 14 16
'''

class_schedule = {}
class_schedule["english"] = {"start":9, "end":10}
class_schedule["math"] = {"start":9, "end":11}
class_schedule["cs"] = {"start":10, "end":12}
class_schedule["music"] = {"start":12, "end":14}
class_schedule["art"] = {"start":13, "end":15}
class_schedule["program"] = {"start":14, "end":16}

selected_coursees = []

if __name__ == "__main__":
#    print class_schedule
    start_time = 8
    have_next_course = True
    while have_next_course:
        selected_course = None
        most_low_end_time = 24
        for node in class_schedule:
            if class_schedule[node]["start"] >= start_time:
                if class_schedule[node]["end"] < most_low_end_time:
                    most_low_end_time = class_schedule[node]["end"] 
                    selected_course = node
        if selected_course:
            selected_coursees.append(selected_course)
            start_time=most_low_end_time
        else:
            have_next_course = False
    print selected_coursees
