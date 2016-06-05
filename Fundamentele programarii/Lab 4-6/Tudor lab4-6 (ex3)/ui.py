from controler import *

class expense:
    day = 0
    amount = 0
    type_of = ""


l = []
l2 = []
def show():
    
    for item in l:
        print(item.day,item.amount,item.type_of)

def populate():
    fin = open('a.txt','r')
    for line in fin.readlines():
        a = line.split()
        add_expense(l2,a=int(a[1]),t = a[2],l=l, d=int(a[0]))
    l2[:] = l
 
def print_options():
    print("1: Add a new expense\n2: Remove\n3: Write\n4: Characteristics\n5: Filter\n6: Undo\n0: Exit")

def ui_add_expense2():
    cond = True
    while cond == True:
        try:
            d = int(input("   Insert the day: "))
            a = int(input("   Insert the amount: "))
            t = input("   Insert the type: ")
            if d <= 31:
                cond = False
            else:
                print("Please insert a day <= 31")
        except ValueError:
            print("Please insert correct values")
    
    add_expense(l2,a = a,t = t ,l=l,d=d)
    
def ui_add_expense1():
    
    amou = None
    Type = None
    while type(amou) != int :
        try:
            amou = int(input("  Insert the amount: "))
            
        except ValueError:
            print("Insert only integers")
            
        Type = input("  Insert the type: ")
    
    add_expense(l2,a=amou,t=Type,l=l)

def ui_remove_day():
    
    d = None
    cond = True
    while cond == True:
        try:
            d = int(input("   Insert the day: "))
            if d <= 31:
                cond = False
            else:
                print("Please insert a day <= 31")
        except ValueError:
            print("Please insert only integers")
    test = remove(l2,l=l,day1 = d)
    if test == 1:
        print("Nothing was delete")
        
def ui_remove_days():
     cond = True
     while cond == True:
        try:
            d1 = int(input("   Insert the day 1: "))
            d2 = int(input("   Insert the day 2: "))
            if d1 <= 31 and d2 <= 31:
                cond = False
            else:
                print("Please insert a day <= 31")
        except ValueError:
            print("Please insert only integers")
        
        remove(l2,l=l,day1 = d1, day2 = d2)
def ui_remove():
    Type = input("   Insert a type: ")
    
    remove(l2,l=l,Type = Type)
def ui_replace():
   cond = True
   while cond == True:
      try:
         dd = int(input("   Insert the day: "))
         ty = input("   Insert the type: ")
         amount = int(input("   Insert the amount: "))
         if dd <= 31 and amount > 0:
            cond = False
         else:
            print("Please insert valid values!")
      except ValueError:
         print("Please insert only integers")
   
   
   
   replace(l2,l,dd,amount,ty)
   for item in l2:
        print(item.day,item.amount,item.type_of)
      
def write_greater_than():
   cond = True
   while cond == True:
      try:
         a = int(input("   Insert the amount: "))
         cond = False
      except ValueError:
         print("Please insert only integers")
   q = select(l=l,amount = a)
   if(len(q) == 0):
      print("Nothing here")
   else:
      for i in q:
         print(i[0],i[1],i[2])
   
def write_less_than():
   cond = True
   while cond == True:
      try:
         dd = int(input("   Insert the day: "))
         amount = int(input("   Insert the amount: "))
         if dd <= 31 and amount > 0:
            cond = False
         else:
            print("Please insert valid values!")
      except ValueError:
         print("Please insert only integers")
   q = select(l=l,day = dd, amount= amount)
   if(len(q) == 0):
      print("Nothing here")
   else:
      for i in q:
         print(i[0],i[1],i[2])
def write_all():
   t = input("   Insert the type: ")
   q=select(l=l,Type=t)
   for i in q:
      print(i[0],i[1],i[2])
   if(len(q) == 0):
      print("Nothing here")

def ui_sum_of():
   t = input("   Insert the type: ")
   print("There is ",sum_of(l,t),"expense of type: ",t)
def ui_max_day():
   print("The day with the maximum expense is",max_day(l))
   
def ui_exact():
    cond = True
    while cond == True:
      try:
         amount = int(input("   Insert the amount: "))
         if amount > 0:
            cond = False
         else:
            print("Please insert a valid value!")
      except ValueError:
         print("Please insert only integers")
    list1 = exact(l,amount)
    if len(list1) > 0:
        
        print("The day in which exactly",str(amount),"were spend are:",list1)
    else:
        print("Nothing here")
def ui_asc_sort():
   print(asc_sort(l))
   print("The solution is of the form [d,a] where d is the day and a is the total expense from that day")
       
def ui_desc_sort():
   types = get_type(l)
   for t in types:
       print(t,":",desc_sort(l,t))
       
def ui_filter_type():
    Type = input("Insert the type: ")
    List = filter_type(Type,l)
    for i in List:
        print(i.day,i.type_of,i.amount)
    if len(List) == 0:
        print("Nothing here")
    
def ui_filter_type_amount():
    Type = input("   Insert the type: ")
    
    try:
         amount = int(input("   Insert the amount: "))
         if amount > 0:
            cond = False
         else:
            print("Please insert a valid value!")
    except ValueError:
         print("Please insert only integers")
    List = filter_type_amount(Type,amount,l) 
    for i in List:
        print(i.day,i.type_of,i.amount)
    if len(List) == 0:
        print("Nothing here")
        
def ui_undo():
    undo(l,l2)
def print_filter_options():
    print("1:  Filter by type\n2:  Filter by type and amount")
def print_add_options():
    print("1:  Add an expense in current day\n2:  Add an expense in an other day\n0:  Back")
def print_remove_options():
    print("1:  Remove from a day\n2:  Remove all expenses between 2 days\n3:  Remove a expense type\n4:  Replace\n0:  Back")
def print_write_options():
    print("1:   Write the expenses greater than: \n2:   Write the expenses less than:   \n3:   Write all the expense for TYPE: ")
def print_write_characteristics():
    print("1:   Sum \n2:   Max day\n3:   Exact \n4:   Asc sort day\n5:   Desc sort type")

def mainMenu():
   
   while True:
        print()
        print_options()
        
        opt = None
        try:
            opt = int(input("Enter your option: "))
        except ValueError:
            print("Please insert only integers")
            
        if type(opt) == int:
            if opt == 1:
                cond = True
                while cond == True :
                    print_add_options()
                    try:
                        opt2 =  int(input("Insert yout choose: "))
                        if opt2 <= 2:
                            cond = False
                        else :
                             print("Please insert a valid choise")
                    except ValueError:
                        print("Insert only integer")
                if(opt2 == 2):
                    ui_add_expense2()
                elif opt2 == 1:
                    ui_add_expense1()
                elif opt2 == 0:
                    pass
                else:
                    print("Please insert a valid choise")
                    
                    
            elif opt == 2 :
                cond = True
                while cond == True:
                    print_remove_options()
                    try:
                        opt2 = int(input("Insert yout choose: "))
                        if opt2 <= 4:
                            cond = False
                        else:
                             print("Please insert a valid choise")
                    except ValueError:
                       print("Insert only integer")


                if opt2 == 1:
                    ui_remove_day()
                elif opt2== 2:
                    ui_remove_days()
                elif opt2 == 3:
                    ui_remove()
                elif opt2 == 4:
                    ui_replace()
                elif opt2 == 0:
                    pass
                else:
                    print("Please insert a valid choise")
            elif opt == 3:
               cond = True
               while cond == True:
                  print_write_options()
                  try:
                     opt2 = int(input("Insert yout choose: "))
                     if opt2 <= 3:
                        cond = False
                     else:
                        print("Please insert a valid choise")
                  except ValueError:
                     print("Insert only integer")
               if opt2 == 1:
                  write_greater_than()
               elif opt2 == 2:
                  write_less_than()
               elif opt2 == 3:
                  write_all()
               else:
                  print("Please insert a valid choise")
            elif opt == 4:
               cond = True
               while cond == True:
                  print_write_characteristics()
                  try:
                     opt2 = int(input("Insert yout choose: "))
                     if opt2 <= 5:
                        cond = False
                     else:
                        print("Please insert a valid choise")
                  except ValueError:
                     print("Insert only integer")
               if opt2 == 1:
                  ui_sum_of()
               elif opt2 == 2:
                  ui_max_day()
               elif opt2 == 3:
                  ui_exact()
               elif opt2 == 4:
                  ui_asc_sort()
               elif opt2 == 5:
                  ui_desc_sort()
               else:
                  print("Please insert a valid choise")
            elif opt==5:
               cond = True
               while cond == True:
                  print_filter_options()
                  try:
                     opt2 = int(input("Insert yout choose: "))
                     if opt2 <= 2:
                        cond = False
                     else:
                        print("Please insert a valid choise")
                  except ValueError:
                     print("Insert only integer")
               if opt2 == 1:
                  ui_filter_type()
               elif opt2 == 2:
                  ui_filter_type_amount()
               else:
                   print("Please insert a valid choise")
            elif opt == 6:
                #show()
                #for item in l2:
                #    print(item.day,item.amount,item.type_of)
                #print()
                ui_undo()
                #print()
                #show()
                #print()
                #for item in l2:
                #    print(item.day,item.amount,item.type_of)
            elif opt==9:
                show()
            elif opt == 0:
                return 












 
