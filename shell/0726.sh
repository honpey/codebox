
cat get_book_tel.txt | sed -n '/name/{:a;n;/book/{p;ta}}'

