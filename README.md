**Identitas Mahasiswa**
•	Nama: Garrison Tanvanno 
•	NIM: 03082230011
•	Kelas: 23TI1

**Deskripsi Tugas**
•	Bangun ruang yang dimodelkan
  > Sandwich/ roti lapis yang terdiri dari roti, ham, selada, dan acar.
•	Penjelasan singkat mengenai pemodelan yang dibuat
  > Objek sandwich dibuat dengan menyusun beberapa balok tipis untuk roti dan isiannya. Model ini terdiri dari:
    –	Roti atas & bawah (balok tipis warna krem).
    –	Selada (balok tipis, lebih lebar, berwarna hijau, diputar sedikit).
    –	Ham (balok tipis warna merah muda).
    –	Acar/pickle (kubus kecil pipih warna hijau).
    –	Model ditampilkan dalam ruang 3D menggunakan OpenGL dengan transformasi, pencahayaan, dan pewarnaan.

**Kode Program**
> File proyek terlampir. Struktur dari folder proyek tersebut yaitu:
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

**Cara Menjalankan Program**
•	Build Project: Buka OpenGL_Sandwich.sln di Visual Studio, pastikan semua library (GLFW, GLAD, glm, stb) tersedia, lalu build project.
•	Jalankan Program: Tekan tombol Run atau F5 untuk menjalankan program.
•	Kontrol Kamera:
  –	Gerakan maju/ mundur/ kiri/ kanan: W/ S/ A/ D.
  –	Rotasi kamera: Gerakkan mouse.
•	Kontrol Objek:
  –	Rotasi sandwich: Tekan tombol ← (kiri) atau → (kanan).
  –	Scaling sandwich: Tekan tombol ↑ (atas) atau ↓ (bawah).
•	Pengamatan Scene: Gunakan kombinasi pergerakan kamera dan rotasi/scale objek untuk melihat sandwich dari berbagai sudut pandang.

