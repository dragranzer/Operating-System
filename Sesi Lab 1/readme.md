# Latihan Sesi Lab 1

## Soal 1
> Buatlah sebuah program bash script yang dapat mengolah bilangan-bilangan yang diinputkan sebagai argumen! Bila jumlah argumen yang diinputkan ganjil, tampilkan jumlah bilangan-bilangan tersebut. Bila genap, tampilkan "Anda belum beruntung, coba lagi." Contoh :
<pre>
$ bash script.sh 4 1 1
Output: 6
$ bash script.sh 3 3
Output: Anda belum beruntung, coba lagi.
</pre>

## Soal 2
> Membuat task scheduling menggunakan crontab untuk membuat log yang berisi size dari direktori /home/<user>/Downloads dalam human readable format. Task berjalan setiap 15 menit pada pukul 8 sampai 17. File log disimpan pada direktori /home/<user>/log/ dengan format nama sesuai command `date`.

## Soal 3
> Lakukan download dengan command wget https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data untuk mendapatkan dataset. Buatlah sebuah program awk yang dapat menampilkan hasil perkalian dari kolom '**petal length in cm**' dan '**petal width in cm**' dengan format 2 angka di belakang koma hanya untuk record dengan kolom '**class**' yang mengandung string ‘**Iris-setosa**’ dan memiliki nilai ‘**sepal length in cm**’ lebih dari **5.4** berdasarkan dataset tersebut! Tampilkan hasil dengan format “**Luas petal pada baris n adalah y.yy**” dimana “**n**” adalah baris ke berapa record tersebut dan “**y.yy**” adalah hasil perkaliannya. Informasi atribut dapat dilihat di https://archive.ics.uci.edu/ml/datasets/iris/
