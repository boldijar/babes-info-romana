#include <iostream>
#include <string>
#include <float.h>
#include "arrmanip.h"
#include "node.h"

void MakeIntArrayNull(int* arr, int length)
{
    for(int i=0; i<length; i++)
        arr[i]=0;
}

/// Adauga un element la sfarsitul unei List<double>
void addToList(List<double> &list,double e)
{
    list.addLast(e);
}

void addToList(List<double> &list, double e, unsigned int pos)
{
    //List<double> temp = List<double>();
    double temp;
    List<double>::iterator it = list.begin();

    if(pos >= list.countElements()+1)
    {
        list.addLast(e);
    }
    else
    {


        while(it.hasNext() != 0)
        {
            if(pos == 1)
            {
                temp = it.getElement();
                it.setElement(e);
                e=temp;
                it.nextElement();
            }
            else
            {
                pos--;
                it.nextElement();
            }
        }
        //it.setElement(e);
        temp = it.getElement();
        it.setElement(e);
        list.addLast(temp);
    }
}

void removeFromList(List<double> &list, unsigned int pos)
{
    List<double>::iterator it1 = list.begin();
    List<double>::iterator it2 = list.begin();
    it1.nextElement();

    if(pos >= list.countElements())
    {
        list.removeLast();
    }
    else
    {


        while(it1.hasNext())
        {
            if(pos == 1)
            {
                it2.setElement(it1.getElement());
                it1.nextElement();
                it2.nextElement();
            }
            else
            {
                pos--;
                it1.nextElement();
                it2.nextElement();
            }
        }

        it2.setElement(it1.getElement());
        list.removeLast();
    }
}

void removeFromList(List<double>& list, unsigned int start, unsigned int end)
{
    int steps=end - start + 1;
    if(steps < 0) return ;
    while(steps-- != 0)
        removeFromList(list,start);
    //if(steps == 0)
    //removeFromList(list,start);
}

void replaceAll(List<double>& list, List<double>& subList, List<double>& withList)
{
    List<double>::iterator it1 = list.begin();
    List<double>::iterator it2 = subList.begin();
    int counter, i=0, j=0, found=0, countOcurrences=0;
    int* posArray = new int[(int)(list.countElements()/subList.countElements())+1];
    MakeIntArrayNull(posArray,(int)(list.countElements()/subList.countElements())+1);
    while(it1.hasNext())
    {
        j++;
        while(it2.hasNext())
        {
            if(it1.getElement() == it2.getElement())
            {
                //found=j;
                counter++;
                j++;
                if(it1.hasNext())
                    it1.nextElement();
            }
            else counter=0;

            /*if(counter == subList.countElements()) // s-au gasit toate;
            {
                // se retine pozitia unde au fost gasite
                posArray[i++] = j;
            }*/
            it2.nextElement();
        }
        // pentru ultimul el care nu e verificat in while
        if(it1.getElement() == it2.getElement())
        {
            counter++;
            //if(subList.countElements()==1) found=j; //j++;
        }
        if(counter == subList.countElements()) // s-au gasit toate;
            // se retine pozitia unde au fost gasite
        {
            found=j-counter+1;
            posArray[i++] = found;

            counter=0;

            //if(subList.countElements()==1) counter=0;
        }
        //
        if(it1.hasNext())
        {
            it1.nextElement();
            it2 = subList.begin();
        }
    }
    //
    //
    //
    countOcurrences=i;
    it1 = withList.begin();
    j=0;
    counter =0;
    // am reusit sa iau pozitiile si sa le stochez intr-o lista
    for(i=0; i<countOcurrences; i++)
    {
        removeFromList(list,posArray[i]-counter, posArray[i]+ subList.countElements() - counter - 1);
        //std::cout<<"X: "<<list.countElements();
        while(it1.hasNext())
        {
            addToList(list,it1.getElement(),posArray[i]-counter);
            it1.nextElement();
        }
        addToList(list,it1.getElement(),posArray[i]-counter);
        counter = subList.countElements() - withList.countElements();
        it1 = withList.begin();
    }
}

int isPrime(int nr)
{
    if(nr < 2) return 0;
    if( nr % 2==0 && nr != 2) return 0;
    for(int d=3; d*d<=nr ; d+=2)
        if(nr%d==0)
            return 0;
    return 1;
}

int isOdd(int nr)
{
    if(nr%2==0) return 0;
    return 1;
}

void getPrimes(List<double>& list, List<double>& returnList, unsigned int start, unsigned int end)
{
    List<double>::iterator it1 = list.begin();
    //List<double>::iterator it2 = returnList.begin();
    // parcurgem lista si cautam nr prime
    int count=end-start+1;
    while(--start != 0)
        it1.nextElement();
    while(it1.hasNext())
    {
        if(count-- != 0)
        {
            if(isPrime(it1.getElement()))
                returnList.addLast(it1.getElement());
            it1.nextElement();
        }
        else return;
        //it2.nextElement();
    }
    if(isPrime(it1.getElement()))
        returnList.addLast(it1.getElement());

}

void getOddNumbers(List<double>& list, List<double>& returnList, unsigned int start, unsigned int end)
{
    List<double>::iterator it1 = list.begin();
    int count=end-start+1;
    while(--start != 0)
        it1.nextElement();
    while(it1.hasNext())
    {
        if(count-- != 0)
        {
            if(isOdd(it1.getElement()))
                returnList.addLast(it1.getElement());
            it1.nextElement();
        }
        else return;
        //it2.nextElement();
    }
    if(isOdd(it1.getElement()))
        returnList.addLast(it1.getElement());
}

/*4. Obtain different characteristics of sublists.
        a. sum from 1 to 5 – writes the sum numbers between position
            1 and 5 in the list.
        b. gcd from 1 to 5 -  writes the greatest common divisor of elements
            between position 1 and 5 in the list.

        c. max from 1 to 5 – writes the greater element of the sublist from
            position 1 to 5.
*/

void getSum(List<double>& list, double& sum, unsigned int start, unsigned int end)
{
    List<double>::iterator it1 = list.begin();
    int count=end-start+1;
    sum=0;
    while(--start != 0)
        it1.nextElement();
    while(it1.hasNext())
    {
        if(count-- != 0)
        {
            /*if(isOdd(it1.getElement()))
                returnList.addLast(it1.getElement());*/
            sum+=it1.getElement();
            it1.nextElement();
        }
        else return;
        //it2.nextElement();
    }
    /*if(isOdd(it1.getElement()))
        returnList.addLast(it1.getElement());*/
    sum += it1.getElement();
}

int euclid(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}



void getGCD(List<double>& list, double& sum, unsigned int start, unsigned int end)
{
    List<double>::iterator it1 = list.begin();
    int count=end-start+1;
    sum=0;
    while(--start != 0)
        it1.nextElement();
    while(it1.hasNext())
    {
        if(count-- != 0)
        {
            /*if(isOdd(it1.getElement()))
                returnList.addLast(it1.getElement());*/
            sum+=it1.getElement();
            it1.nextElement();
        }
        else return;
        //it2.nextElement();
    }
    /*if(isOdd(it1.getElement()))
        returnList.addLast(it1.getElement());*/
    sum += it1.getElement();
}

void getMax(List<double>& list, double& max, unsigned int start, unsigned int end)
{
    List<double>::iterator it1 = list.begin();
    int count=end-start+1;
    max=DBL_MIN;
    while(--start != 0)
        it1.nextElement();
    while(it1.hasNext())
    {
        if(count-- != 0)
        {
            if(max < it1.getElement())
                max=it1.getElement();

            it1.nextElement();
        }
        else return;
        //it2.nextElement();
    }
    if(max < it1.getElement())
        max=it1.getElement();
}
/*

5. Filter.
        a. filter prime – retains only the prime numbers.
        b. filter negative –retains only the negative numbers.
*/

int isNegative(int nr)
{
    if(nr < 0) return 1;
    return 0;
}

void getNegatives(List<double>& list, List<double>& returnList, unsigned int start, unsigned int end)
{
    List<double>::iterator it1 = list.begin();
    int count=end-start+1;
    //max=DBL_MIN;
    while(--start != 0)
        it1.nextElement();
    while(it1.hasNext())
    {
        if(count-- != 0)
        {
            if(isNegative(it1.getElement()))
                returnList.addLast(it1.getElement());

            it1.nextElement();
        }
        else return;
        //it2.nextElement();
    }
    if(isNegative(it1.getElement()))
        returnList.addLast(it1.getElement());
}

/*
    6. Undo the last operation.
        a. undo – the last operation that has modified the list of numbers is
            cancelled.

*/
void swapLists(List<double>& list, List<double>& returnList)
{
    List<double>::iterator it1 = list.begin();
    List<double>::iterator it2 = returnList.begin();
    double temp;
    double countElemList2=returnList.countElements();
    double countElemList1=list.countElements();

    while((list.countElements() >= returnList.countElements()) ? it2.hasNext() : it1.hasNext())
    {
        temp = it2.getElement();
        it2.setElement(it1.getElement());
        it1.setElement(temp);
        it1.nextElement();
        it2.nextElement();
    }
    temp = it2.getElement();
    it2.setElement(it1.getElement());
    it1.setElement(temp);
    while((list.countElements() >= returnList.countElements()) ? it1.hasNext() : it2.hasNext())
    {
        if(list.countElements() > returnList.countElements())
        {
            it1.nextElement();
            returnList.addLast(it1.getElement());
            //it1.nextElement();
        }
        else
        {
            it2.nextElement();
            list.addLast(it2.getElement());
        }
    }

    // stergere date in plus

    if(list.countElements() > returnList.countElements())
    {
        removeFromList(returnList,countElemList1+1,countElemList2);
    }
    else
    {
        removeFromList(list,countElemList2+1,countElemList1);
    }
}

void undo(List<double>& list, List<double> returnList)
{
    List<double>::iterator it = returnList.begin();

    // golesc lista
    removeFromList(list,1,list.countElements());
    for(int i= 1; i<=returnList.countElements(); i++)
    {
        list.addLast(it.getElement());
        it.nextElement();
    }
}






