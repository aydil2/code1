No	Scenario	Class	Method	Data Input	Expected Result	Actual Result	Status
1	Menampilkan daftar mata pelajaran dan KKM	datanilai	tampilMapel()	Program dijalankan	Program menampilkan 5 mata pelajaran beserta KKM	Sesuai tampilan program	Pass
2	Input nama siswa dengan huruf	Siswa	inputSiswa()	Nama: Andi	Nama diterima dan disimpan	Sesuai input	Pass
3	Input nama siswa mengandung angka	Siswa	inputSiswa()	Nama: Andi123	Program menolak input dan menampilkan pesan "Nama tidak boleh mengandung angka!"	Program meminta input ulang	Pass
4	Input NIS dengan angka	Siswa	inputSiswa()	NIS: 12345	NIS diterima dan disimpan	Sesuai input	Pass
5	Input NIS dengan huruf	Siswa	inputSiswa()	NIS: ABC	Program menolak dan menampilkan pesan "NIS harus angka!"	Program meminta input ulang	Pass
6	Input nilai mata pelajaran valid	datanilai	inputNilai()	Nilai: 80	Nilai diterima karena berada antara 0-100	Nilai tersimpan	Pass
7	Input nilai di luar batas	datanilai	inputNilai()	Nilai: 120	Program menolak dan menampilkan pesan "Nilai harus antara 0 - 100!"	Program meminta input ulang	Pass
8	Menghitung rata-rata nilai	datanilai	hitungRata()	Nilai: 80,85,90,75,88	Program menghitung rata-rata dengan benar	Rata-rata = 83.60	Pass
9	Menentukan predikat berdasarkan rata-rata	datanilai	predikat()	Rata-rata: 83	Program memberi predikat B	Predikat tampil B	Pass
10	Menyimpan rapor ke file	Siswa & datanilai	cetakFile()	Pilih Y saat konfirmasi	File rapor12345.txt dibuat dan berisi data rapor	File berhasil dibuat	Pass