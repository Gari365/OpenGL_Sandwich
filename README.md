# Identitas Mahasiswa 
  •	Nama: Garrison Tanvanno 
  •	NIM: 03082230011
  •	Kelas: 23TI1

# 1.	Tujuan 
  •	Mampu menggunakan library pemrograman OpenGL untuk membuat, menampilkan, serta memanipulasi model 3D.
  •	Memahami konsep dasar pemodelan bangun ruang 3D menggunakan vertex, indeks, dan atribut warna.
  •	Mahasiswa dapat menerapkan transformasi 3D (rotasi, translasi, dan scaling) pada objek dengan memahami tool atau fitur yang telah tersedia dalam library OpenGL.
  •	Mahasiswa memahami teknik rendering sederhana, yaitu proyeksi, perspektif, shader, pencahayaan (lighting), pewarnaan, dan pencitraan (rasterization).

# 2.	Deskripsi Tugas 
  •	Bangun ruang yang dimodelkan
    ^ Sandwich/ roti lapis yang terdiri dari roti, ham, selada, dan acar.
  •	Penjelasan singkat mengenai pemodelan yang dibuat
    ^ Objek sandwich dibuat dengan menyusun beberapa balok tipis untuk roti dan isiannya. Model ini terdiri dari:
      –	Roti atas & bawah (balok tipis warna krem).
      –	Selada (balok tipis, lebih lebar, berwarna hijau, diputar sedikit).
      –	Ham (balok tipis warna merah muda).
      –	Acar/pickle (kubus kecil pipih warna hijau).
      –	Model ditampilkan dalam ruang 3D menggunakan OpenGL dengan transformasi, pencahayaan, dan pewarnaan.

# 3.	Implementasi Program 
  a. Pemodelan Bangun Ruang 
    ^ Pemodelan dilakukan dengan fungsi buatan sendiri addCube() untuk memperhitungkan vertex, sumbu normal, dan indeks dari sebuah balok/kubus. Parameter posisi, ukuran (scale), dan warna diberikan agar tiap bagian sandwich dapat dibedakan.
  b. Transformasi 3D (Boleh di tambahkan Teknik – Teknik yang lebih menarik lain nya dan yang dipahami) 
    •	Rotasi: Objek sandwich diputar secara kontinu pada sumbu Y agar terlihat dari berbagai sudut pandang.
    •	Translasi: Tiap lapisan (roti, selada, ham, acar) diposisikan dengan pergeseran pada sumbu Y, dan objek acar juga memiliki variasi pada posisi sumbu X dan Z.
    •	Scaling: Digunakan untuk mengatur ukuran / scale dari sadwich menjadi lebih besar/ kecil, relevan terhadap pusat objek.
  c.	Rendering
    •	 Lighting: Menggunakan pencahayaan sederhana (spread light) untuk menampilkan efek terang-gelap sesuai orientasi permukaan. Juga mengatur nilai specular light dan ambient light untuk memberikan efek yang lebih realistis.
    •	Pewarnaan: Setiap objek diberi warna solid, misalnya roti berwarna krem, selada hijau, ham merah muda, acar hijau muda.
  d.	Kamera/ Projection
    •	Pergerakan posisi kamera: Kamera dapat digerakkan maju, mundur, kiri, dan kanan menggunakan tombol W, S, A, dan D.
    •	Rotasi kamera: Kamera dapat diputar dengan mouse untuk melihat model dari berbagai sudut.
    •	Metode proyeksi: Menggunakan proyeksi perspektif 3D (perspective projection) agar tampilan model lebih realistis dan sesuai dengan kedalaman scene.

# 4.	Hasil dan Dokumentasi 
  •	Tampak samping
 
  •	Tampak depan
 
  •	Tampak atas
 
  •	Skala & Rotasi

# 5.	Kode Program
  ^ File proyek terlampir. Struktur dari folder proyek tersebut yaitu:
    –	main.cpp → File utama untuk inisialisasi OpenGL, load shader, buat model sandwich, dan loop render.
    –	default.vert & default.frag → Shader utama untuk me-render sandwich dengan warna dan normal.
    –	light.vert & light.frag → Shader khusus untuk efek pencahayaan sumber cahaya.
    –	Camera.h & Camera.cpp → Kelas untuk mengatur posisi, arah, dan input kontrol kamera 3D.
    –	shaderClass.h & shaderClass.cpp → Kelas pembungkus untuk memuat, compile, dan gunakan shader OpenGL.
    –	Texture.h & Texture.cpp → Kelas untuk memuat dan mengatur tekstur dari gambar PNG (tidak terimplementasi).
    –	stb.cpp → Implementasi library stb_image untuk load file gambar.
    –	VAO.h & VAO.cpp → Kelas untuk mengatur Vertex Array Object.
    –	VBO.h & VBO.cpp → Kelas untuk menyimpan data vertex ke GPU.
    –	EBO.h & EBO.cpp → Kelas untuk menyimpan indeks mesh agar bisa digambar dengan glDrawElements.
    –	glad.c → Loader fungsi OpenGL.
    –	OpenGL_Sandwich.sln / .vcxproj / .vcxproj.filters / .vcxproj.user → File project Visual Studio dan konfigurasi build.
    –	Libraries/ → Folder berisi dependensi tambahan (GLFW, glm, stb, dll).
    –	x64/ → Folder output binary build.

# 6.	Cara Menjalankan Program 
  •	Build Project: Buka OpenGL_Sandwich.sln di Visual Studio, pastikan semua library (GLFW, GLAD, glm, stb) tersedia, lalu build project.
  •	Jalankan Program: Tekan tombol Run atau F5 untuk menjalankan program.
  •	Kontrol Kamera:
    –	Gerakan maju/ mundur/ kiri/ kanan: W/ S/ A/ D.
    –	Rotasi kamera: Gerakkan mouse.
  •	Kontrol Objek:
    –	Rotasi sandwich: Tekan tombol ← (kiri) atau → (kanan).
    –	Scaling sandwich: Tekan tombol ↑ (atas) atau ↓ (bawah).
  •	Pengamatan Scene: Gunakan kombinasi pergerakan kamera dan rotasi/scale objek untuk melihat sandwich dari berbagai sudut pandang.

# 7.	Kesimpulan 
    Dalam proyek ini, saya mempelajari bagaimana memodelkan objek 3D sederhana menggunakan OpenGL, khususnya menggunakan kubus untuk membentuk objek yang lebih kompleks seperti sandwich. Proses ini mengajarkan bagaimana menentukan posisi, ukuran, dan orientasi setiap bagian agar membentuk model yang utuh tanpa celah.
    Selain itu, saya memahami penerapan transformasi 3D seperti rotasi, translasi, dan scaling untuk membuat model dapat berinteraksi dengan input pengguna, serta pentingnya penerapan proyeksi perspektif agar tampilan lebih realistis.
    Begitu juga, penggunaan pencahayaan sederhana dan pewarnaan solid memberikan pengalaman dasar dalam rendering, dan pengaturan kamera interaktif memperkuat pemahaman terhadap navigasi di ruang 3D, yang menjadi fondasi penting untuk pengembangan aplikasi grafis 3D lebih lanjut.
