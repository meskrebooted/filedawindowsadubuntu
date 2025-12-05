#!/bin/bash
mkdir -p ORIGINE/MIEI_FILE
echo "contenuto file 1" > ORIGINE/1.txt
echo "contenuto file 2" > ORIGINE/2.doc
echo "contenuto file a" > ORIGINE/a.txt
echo "contenuto file x" > ORIGINE/x.dll
chmod 444 ORIGINE/2.doc
mv ORIGINE/1.txt ORIGINE/finale.txt
cat ORIGINE/finale.txt
mv ORIGINE/* ORIGINE/MIEI_FILE/
ls ORIGINE/MIEI_FILE
