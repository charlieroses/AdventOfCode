## awk one liners :)

Part 1
```awk
awk -F'[-,]' '((($1<=$3)&&($2>=$4))||(($3<=$1)&&($4>=$2))){i++} END{print i}' input
```

Part 2
```awk
awk -F'[-,]' '((($1<=$3)&&($3<=$2))||(($3<=$1)&&($1<=$4))){i++} END{print i}' input
```
