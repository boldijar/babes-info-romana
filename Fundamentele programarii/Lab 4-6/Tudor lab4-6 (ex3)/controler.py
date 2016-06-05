from copy import deepcopy
import time
from datetime import date

class expense:
    day = 0
    amount = 0
    type_of = ""


today = date.today()

def create_exp_object(d , a, t):
    """"Create an expense object and initialise it with arguments values
    Input: d (integer) = the day of expense
           a (integer) = the amount of expese
           t (string) = type of expese
    Output: Returns an expense object
    """
    e = expense()
    e.day = d
    e.amount = a
    e.type_of = t
    return e



def add_expense(l2,a,t,l=[],d = today.day):
    """ Add a new expense object in the list l
    Input: d (integer) = the day of expense
           a (integer) = the amount of expese
           t (string) = type of expese
    Output: Returns void
    """
    
    l2 = deepcopy(l)
    ex = create_exp_object(d,a,t)
    l.append(ex)
   




def remove(l2,l,day1 = None,day2=None,Type=None):
    """Remeve from the expense list the element which correspond with the
    criteria that we have chosen
    Input: day1(int) = the first day in the month from where we will remove the expenses
                       (or the day from where we will remove the expenses - if we only chose if)
           day2(int) = the last day in the month to where we remone the expenses
           Type(str) = the type of expenses which will be remove
    Output: Returns void     
    """
    l3 =[]
    #l2 = deepcopy(l)
    test = 1
    if type(day1) == int and type(day2) != int and type(Type) != str:
        for item in l:
            if item.day == day1:
                test = 0
                continue
            else:
                l3.append(item)
        l[:] = l3
   # return test

    elif type(day1) == int and type(day2) == int and type(Type) != str:
        for item in l:
            if item.day >= day1 and item.day <= day2:
                continue
            else:
                l3.append(item)
        l[:] = l3
        
    elif type(day1) != int and type(day2) != int and type(Type) == str:
        for item in l:
            item.type_of = item.type_of.strip()
            Type = Type.strip() 
            if item.type_of == Type:
                l.remove(item)
        for item in l:
            if item.type_of == Type:
                l.remove(item)  

def replace(l2,l,day,amount,Type):
    """Replace the amount from a specified day and expense type with an other value
    Input: l - list of the expense
           day - (int) the specified day
           amount - (int) the new amount
           Type - (str) the specified type of expense
    Output: The amount from the specified day and type is replace 
    """
    l2 = deepcopy(l)
    for i in range(0,len(l)):
        if l[i].day == day:      
            l[i].type_of = l[i].type_of.strip()
            Type = Type.strip()  
            if l[i].type_of == Type:    
                l[i].amount = amount

def select(l,day = None, amount = None, Type= None):
    """Select the element from the list whose expense is greater that an value
    or less than a value before a specified day or the element wichi are the same type
    Input: l - the list of expense
           day - (int) the reference day
           amount - (int) the reference amount
           Type - the specified type
    Output: a list of expenses represented in a list [expense.day, expense.amount, expense.type]
    """
    exps = []
    if type(day) != int and type(amount) == int and type(Type) != str:
        for item in l:
            if item.amount > amount:
                l2 = [item.day,item.amount,item.type_of]
                exps.append(l2)
    elif type(day) == int and type(amount) == int and type(Type) != str:
        for item in l:
            if item.amount < amount and item.day < day:
                l2 = [item.day,item.amount,item.type_of]
                exps.append(l2)
    elif type(day) != int and type(amount) != int and type(Type) == str:
        for item in l:
            item.type_of = item.type_of.strip()
            Type = Type.strip()
            if item.type_of == Type:
                l2 = [item.day,item.amount,item.type_of]
                exps.append(l2)
    return exps

def sum_of(l,Type):
    """Return a sum which compute all amounts of a given type of expense
       Input: l - the list of expenses
              Type - the type of expense
       Output: sum_of - (int) the sum required
    """
    sum_of = 0
    for item in l:
        Type = Type.strip()
        item.type_of = item.type_of.strip()
        if Type == item.type_of:
            sum_of += item.amount
    return sum_of

def max_day(l):
    """Return the day with maximum expense
    Input: l - the list of the expenses
    Output: sol - (int) represents the day required 
    """
    sol=0
    sum_max = -1
    for item in l:
        d = item.day
        sum_par= 0
        for e in l:
            if e.day == d:
                sum_par += e.amount
        if sum_max < sum_par:
            sum_max = sum_par
            sol = d
    return sol

def find(l,a):
    for item in l:
        if item == a:
            return 1
    return 0

def exact(l,amount):
    """Return a list which contain the days with a specified expense 
    Input: l - the list of expsense
           amount - (integer) = the specified amount of expense
    Output: sol - list with the days required
    """
    sol =[]
    for item in l:
        d = item.day
        sum_par= 0
        for e in l:
            if e.day == d:
                sum_par += e.amount
        if amount == sum_par:
            if find(sol,d) == 0:
                sol.append(d)
    return sol
def get_days(l):
    sol = []
    for item in l:
        if find(sol,item.day) == 0:
            sol.append(item.day)
    return sol

def order_asc(l):
    for i in range(0,len(l)-1):
        for j in range(i+1, len(l)):
            if l[i][1] > l[j][1]:
                aux = l[i]
                l[i] = l[j]
                l[j] = aux

def order_desc(l):
    for i in range(0,len(l)-1):
        for j in range(i+1, len(l)):
            if l[i][1] < l[j][1]:
                aux = l[i]
                l[i] = l[j]
                l[j] = aux
    
def asc_sort(l):
    """Sort the total daily expense in an ascending order
    Input: l- the list of expenses
    Output: sol - list which contain the days in an ascending order
    """
    sol = []
    days = get_days(l)
    
    for day in days:
        ps = 0
        for item in l:
            if item.day == day:
                ps+=item.amount
        sol.append([day,ps])
    order_asc(sol)
    
    return sol

def find_type(Type,l):
    Type = Type.strip()
    for t in l:
        t = t.strip()
        if t == Type:
            return 1
    return 0

def get_type(l):
    types = []
    for item in l:
        if find_type(item.type_of,types) == 0:
            types.append(item.type_of)
    return types
def desc_sort(l,Type):
    """sort the total daily expenses per category in a descending order
    Input: l - the list of the expenses
           Type - the category request
    Output: sol - A list which have in a descending order the total daily expenses from that category
            of the type [[day,amount]]
    """
    sol = []
    days = get_days(l)
    
    for day in days:
        ps = 0
        for item in l:
            item.type_of = item.type_of.strip()
            Type=Type.strip()
            if item.day == day and item.type_of == Type:
                ps+=item.amount
        sol.append([day,ps])
    order_desc(sol)
    
    return sol

def filter_type(Type,l):
    """Returns a list of expense which have the type specified 
       Input: Type - (str) the type specified
              l - the list of the expens
       Output: sol - the list of the filtred expenses
    """
    sol = []
    for item in l:
        item.type_of = item.type_of.strip()
        Type = Type.strip()
        if item.type_of == Type:
            sol.append(item)
    return sol

def filter_type_amount(Type,amount,l):
    """Returns a list of expense which have the type required and the amount greater
       that the amount specified
       Input: Type - (str) the type specified
              amount- (int) the amount specified
              l - the list of the expens
       Output: sol - the list of the filtred expenses
    """
    sol = []
    for item in l:
        item.type_of = item.type_of.strip()
        Type = Type.strip()
        if item.type_of == Type and item.amount > amount:
            sol.append(item)
    return sol

def undo(l,l2):
    """Copy the l2 in the l
    Input: l - list of the expense which contains the last modifie
           l2 - list of the expense which not contains the last modifie
    Output: the list l is change with list l2
    """
    l = deepcopy(l2)

#tests ----------------------------------
def test_all():
    def test_undo():
        l=[]
        add_expense(l,a=10,t="house",l=l,d=10)
        add_expense(l,a=11,t="food",l=l,d=10)
        add_expense(l,a=112,t="film",l=l,d=12)
        add_expense(l,a=100,t="bike",l=l,d=3)
        add_expense(l,a=110,t="film",l=l,d=5)
        add_expense(l,a=111,t="food",l=l,d=5)
        remove(l,day1=10)
        undo(l,l2)
        
    def test_filter():
        l=[]
        add_expense(l,a=10,t="house",l=l,d=10)
        add_expense(l,a=11,t="food",l=l,d=10)
        add_expense(l,a=112,t="film",l=l,d=12)
        add_expense(l,a=100,t="bike",l=l,d=3)
        add_expense(l,a=110,t="film",l=l,d=5)
        add_expense(l,a=111,t="food",l=l,d=5)
        assert len(filter_type_amount("food",50,l)) == 1
        assert len(filter_type("film",l)) == 2 
    test_filter()
    
    def test_desc_sort():
        l=[]
        add_expense(l,a=10,t="house",l=l,d=10)
        add_expense(l,a=11,t="food",l=l,d=10)
        add_expense(l,a=112,t="film",l=l,d=12)
        add_expense(l,a=100,t="bike",l=l,d=3)
        add_expense(l,a=110,t="film",l=l,d=5)
        add_expense(l,a=111,t="food",l=l,d=5)
        assert desc_sort(l,"food") == [[5, 111], [10, 11], [3, 0], [12, 0]]
    test_desc_sort()
    
    def test_asc_sort():
        l=[]
        add_expense(l,a=10,t="house",l=l,d=10)
        add_expense(l,a=11,t="food",l=l,d=10)
        add_expense(l,a=112,t="film",l=l,d=12)
        add_expense(l,a=100,t="bike",l=l,d=3)
        add_expense(l,a=110,t="film",l=l,d=5)
        add_expense(l,a=111,t="food",l=l,d=5)
        assert asc_sort(l) == [[10, 21], [3, 100], [12, 112], [5, 221]]
    test_asc_sort()
    
    def test_add():
        
        l=[]
        assert(len(l) == 0)
        add_expense(l,a=101,t="house",l=l,d=10)
        assert(len(l) == 1)
        add_expense(l,a=11,t="house",l=l)
        assert(len(l) == 2)               
            
    test_add()

    def test_remove():
        
        l=[]
        assert(len(l) == 0)
        add_expense(l,a=10,t="house",l=l,d=10)
        add_expense(l,a=101,t="house",l=l,d=10)
        add_expense(l,a=11,t="food",l=l,d=11)
        add_expense(l,a=12,t="film",l=l,d=12)
        add_expense(l,a=100,t="bike",l=l,d=30)
        remove(l,l,day1=10)
        assert(len(l)==3)
        remove(l,l,day1=1,day2=13)
        assert(len(l) == 1)
        remove(l,l,Type = "bike")
        assert(len(l) == 0)
    test_remove()

    def test_select():
        
        l=[]
        assert(len(l) == 0)
        add_expense(l,a=101,t="house",l=l,d=10)
        add_expense(l,a=101,t="food",l=l,d=11)
        add_expense(l,a=112,t="film",l=l,d=12)
        add_expense(l,a=100,t="bike",l=l,d=30)
        ex = select(l,amount = 105)
        assert(len(ex) == 1)
        ex = select(l,day = 13,amount = 105)
        assert(len(ex) == 2)
        ex = select(l,Type = "film")
        assert(len(ex) == 1)
    test_select()
    
    def test_exact():

        l=[]
        add_expense(l,a=10,t="house",l=l,d=10)
        add_expense(l,a=11,t="food",l=l,d=10)
        add_expense(l,a=112,t="film",l=l,d=12)
        add_expense(l,a=1000,t="bike",l=l,d=3)
        add_expense(l,a=110,t="film",l=l,d=5)
        add_expense(l,a=2,t="food",l=l,d=5)
        assert exact(l,21) == [10]
        assert exact(l,1000) == [3]
        assert exact(l,112) == [12,5]
    test_exact()

    def test_max_day():
        l=[]
        add_expense(l,a=10,t="house",l=l,d=10)
        add_expense(l,a=11,t="food",l=l,d=10)
        add_expense(l,a=112,t="film",l=l,d=12)
        add_expense(l,a=100,t="bike",l=l,d=3)
        add_expense(l,a=110,t="film",l=l,d=5)
        add_expense(l,a=111,t="food",l=l,d=5)
        assert max_day(l) == 5

    test_max_day()

    def test_sum_of():
        l=[]
        add_expense(l,a=10,t="house",l=l,d=10)
        add_expense(l,a=11,t="food",l=l,d=10)
        add_expense(l,a=112,t="food",l=l,d=12)
        add_expense(l,a=100,t="bike",l=l,d=3)
        add_expense(l,a=110,t="film",l=l,d=5)
        add_expense(l,a=111,t="food",l=l,d=5)
        assert sum_of(l,"film") == 110
        assert sum_of(l,"food") == 234
    test_sum_of()
        
    def test_replace():
        l=[]
        add_expense(l,a=10,t="house",l=l,d=10)
        replace(l,l,10,99,"house")
        assert l[0].amount == 99
    test_replace()

    def test_select():
        l=[]
        add_expense(l,a=10,t="house",l=l,d=10)
        add_expense(l,a=11,t="food",l=l,d=10)
        add_expense(l,a=112,t="film",l=l,d=12)
        add_expense(l,a=100,t="bike",l=l,d=3)
        add_expense(l,a=110,t="film",l=l,d=5)
        add_expense(l,a=112,t="food",l=l,d=5)
        assert select(l,amount = 111) == [[12, 112, 'film'], [5, 112, 'food']]
        assert select(l,Type = "bike") == [[3, 100, 'bike']]
        assert select(l,amount = 11,day = 12) == [[10, 10, "house"]]
    test_select()





    

