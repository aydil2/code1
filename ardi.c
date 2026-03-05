1,Menampilkan daftar mata pelajaran,Mapel,tampilkanMapel(),Program dijalankan,Menampilkan 5 mata pelajaran beserta KKM,Sesuai tampilan program,Pass
2,Input identitas siswa,Identitas,inputIdentitas(),Nama: Budi,Nama berhasil disimpan,Nama tampil di rapot,Pass
3,Input NIS angka valid,Identitas,inputIdentitas(),NIS: 12345,NIS diterima karena semua karakter angka,NIS tersimpan di data siswa,Pass
4,Input NIS mengandung huruf,Identitas,inputIdentitas(),NIS: 12A45,Program menolak dan menampilkan pesan kesalahan,Program meminta input ulang,Pass
5,Input nilai dalam batas valid,Nilai,inputNilai(),Nilai: 85,Nilai diterima karena berada antara 0-100,Nilai tersimpan di array nilai,Pass
6,Input nilai di luar batas,Nilai,inputNilai(),Nilai: 120,Program menolak dan menampilkan pesan "Nilai harus antara 0-100!",Program meminta input ulang nilai,Pass
7,Penentuan status kelulusan,Nilai,inputNilai(),Nilai: 80 KKM:76,Status menjadi LULUS,Status LULUS tampil di rapot,Pass
8,Menghitung rata-rata nilai,Identitas,inputNilai(),Nilai:80 85 90 75 88,Rata-rata dihitung dan disimpan di id->rata,Rata-rata tampil di rapot,Pass
9,Menentukan predikat nilai,Identitas,inputNilai(),Rata-rata:83,Program memberi predikat B,Predikat B tampil di rapot,Pass
10,Menyimpan rapot ke file,Nilai & Mapel,simpanRapot(),Tekan Y saat konfirmasi,File Rapot_NIS.txt dibuat dan berisi data rapot,File berhasil tersimpan,Pass