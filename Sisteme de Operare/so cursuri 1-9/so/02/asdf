BEGIN {
}

{
    sum[$1] = sum[$1] + $3
    num[$1] = num[$1] + 1
}

END {
    for(nume in sum) {
        print sum[nume]/num[nume], nume
    }
}
