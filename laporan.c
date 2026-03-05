1,Menampilkan daftar mata pelajaran,datanilai,tampilMapel(),Program dijalankan,Menampilkan 5 mata pelajaran beserta KKM,Sesuai tampilan program,Pass
2,Input nama siswa dengan huruf,Siswa,inputSiswa(),Nama: Andi,Nama diterima dan disimpan,Sesuai input,Pass
3,Input nama siswa mengandung angka,Siswa,inputSiswa(),Nama: Andi123,Program menolak input dan meminta ulang nama,Nama harus huruf saja,Pass
4,Input NIS dengan angka,Siswa,inputSiswa(),NIS: 12345,NIS diterima dan disimpan,Sesuai input,Pass
5,Input NIS dengan huruf,Siswa,inputSiswa(),NIS: ABC,Program menolak input dan meminta ulang,NIS harus angka,Pass
6,Input nilai mata pelajaran valid,datanilai,inputNilai(),Nilai: 80,Nilai diterima karena dalam rentang 0-100,Nilai tersimpan,Pass
7,Input nilai di luar batas,datanilai,inputNilai(),Nilai: 120,Program menolak input dan meminta ulang nilai,Muncul pesan nilai harus 0-100,Pass
8,Menghitung rata-rata nilai,datanilai,hitungRata(),80 85 90 75 88,Rata-rata dihitung dengan benar,Rata-rata tampil di layar,Pass
9,Menentukan predikat nilai,datanilai,predikat(),Rata-rata: 83,Program menampilkan predikat B,Predikat tampil sesuai,Pass
10,Menyimpan rapor ke file,Siswa & datanilai,cetakFile(),Input Y,File rapor dibuat dengan nama raporNIS.txt,File berhasil tersimpan,Pass