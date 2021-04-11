# Latihan Sesi Lab 2
Sistem Operasi 2021

## Soal 1
Modifikasi code [soal1.c](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/blob/master/2021/Modul2/soal1.c) agar output nya menjadi angka urut dari 0 sampai 100, tanpa menghapus fungsi yang sudah ada dan menggunakan wait.
## Soal 2
Buatlah sebuah program yang dapat mengcopy folder beserta semua isi dari folder di /home/{USER}/Downloads ke dalam sebuah folder dengan format nama tanggal-bulan-tahun_jam:menit:detik (contoh: 26-03-2021_16:22:09). Gunakan fork, exec, dan wait.
## Soal 3
Buatlah sebuah daemon yang berjalan setiap 10 detik yang dapat melakukan backup isi dari file error.txt yang disimpan dalam file error.log.{no} (contoh: error.log.1 , error.log.2, … ) lalu menghapus isi error.txt tersebut sehingga file tersebut kosong kembali. Tidak diperbolehkan menggunakan exec dan system.
