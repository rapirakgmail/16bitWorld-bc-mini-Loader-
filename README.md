# BCC-SimpleLoader
# รายละเอียด
    - วัตถุประสงค์เพื่อเสริมความเข้าใจเกี่ยวกับกลไกลการทำงานของ loader module ของระบบปฎิบัติการ
    - โปรแกรมรองรับเฉพาะระบบปฎิบัติการ DOS 16 bit และ DOXBOX
    - โปรแกรมรองรับเฉพาะการโหลดแฟ้ม ".COM" เท่านั้น
    - พัฒนาโดยใช้  Borland C (3.x) ที่ compile ด้วย tiny model

# แฟ้ม
  1. SIMPLELD.C : source file ของ loader
     การ compile
       bcc simpleld.c    (ได้ simpleld.exe) 
  3. APP2.C : source file ของโปรแกรมตัวอย่าง
     การ compile
       bcc app2.c (ได้ app2.exe)
       exe2bin app2.exe app2.com
    NOTE : exe2bin โปรแกรมที่ทำหน้าที่แปลง ".EXE" ให้เป็น ".COM"
