# Lexical-Analyzer-for-Psi-

## Bu proje,Psi++ programlama dili için [Lexical Analyzer](https://www.guru99.com/compiler-design-lexical-analysis.html) yapmayı amaçlamaktadır.

### Her bir Tokenin kuralları aşağıdaki dokümanda verilmiştir.

![Adsız](https://user-images.githubusercontent.com/65908597/193408622-f860efd2-c544-4e6a-914c-dec055022881.png)
![Adsız2](https://user-images.githubusercontent.com/65908597/193408729-e66a286b-2abe-401d-9f28-0ab3c4394ed1.png)
#### 1.Dosya girdileri ve çıktıları
![Adsız3](https://user-images.githubusercontent.com/65908597/193409012-543a16e2-8d63-4a6b-9ff1-b03d6566ed82.png)

* Yorum satırları açılıp kapatılmazsa (ilk dosya girdisinde son kısımda yorum kapatılmamıştır) program hata mesajı verir ve bu tokenlar çıktıya eklenmeyerek tokenlar oluşturulmaya devam edilmiştir.
![Adsız4](https://user-images.githubusercontent.com/65908597/193409240-afb78cef-38b0-4ca9-b236-11f07352b670.png)

#### 2. dosya girdileri ve çıktıları
![Adsız6](https://user-images.githubusercontent.com/65908597/193409402-0f618435-05e8-47bf-b504-f87cc485764d.png)
* String ifadelerinde tırnaklar(ikinci dosya girdisinde *this is a string) açılıp kapatılmazsa hata mesajı verir ve bu tokenlar çıktıya eklenmeyerek tokenlar oluşturulmaya devam edilmiştir.
![Adsız7](https://user-images.githubusercontent.com/65908597/193409497-f986b476-eab3-4480-bea5-1bcfb2b8d108.png)

#### 3. dosya girdileri ve çıktıları

![Adsız8](https://user-images.githubusercontent.com/65908597/193409639-415c76cd-c25b-4947-b752-7d0238101f58.png)

* 10 basamaktan daha uzun bir integer girildiği için ve 20 karakterden daha uzun bir identifier girildiği için hata mesajı verilmiş ve bu tokenlar çıktıya eklenmeyerek tokenlar oluşturulmaya devam edilmiştir.


![Adsız9](https://user-images.githubusercontent.com/65908597/193409791-4e813dac-5e8e-42b3-9a84-34799ee2cf89.png)


