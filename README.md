# BCC-SimpleLoader
# รายละเอียด
    - วัตถุประสงค์เพื่อเสริมความเข้าใจเกี่ยวกับกลไกลการทำงานของ loader module ของระบบปฎิบัติการ
    - โปรแกรมรองรับเฉพาะระบบปฎิบัติการ DOS 16 bit และ DOXBOX
    - โปรแกรมรองรับเฉพาะการโหลดแฟ้ม ".COM" เท่านั้น
    - พัฒนาโดยใช้  Borland C (3.x) ที่ compile ด้วย tiny model

# แฟ้ม
      1. SIMPLELD.C : source file ของ loader
             การ compile
             bcc -mt simpleld.c    (ได้ simpleld.exe)
      
      2. APP2.C : source file ของโปรแกรมตัวอย่าง
            การ compile
            bcc -mt -lt app2.c     (ได้ app2.com)

# Vdo  การ compile & run


https://github.com/user-attachments/assets/7bf8b953-ca69-4ec1-a293-0b4c4aa5e048

# ขั้นตอนการเตรียม enviroment สามารถศึกษาได้จาก
   https://github.com/rapirakgmail/16bitWorld-bcc-env
 
# ขั้นตอนการเตรียม enviroment
    
     1. ติดตั้ง DOSBOX หรือสร้าง VM ของ DOS16bit ตั้งแต่ 3.x หรือ freedos
     2. ติดตั้ง Borland C (3.x)
     3. ติดตั้ง 7-Zip เพื่อแตกแฟ้ม ".img" ของ borlandc
           https://www.7-zip.org/
    
    NOTE :  การสร้าง enviroment ในการสร้รงโปรแกรม
        https://github.com/rapirakgmail/16bitWorld-bcc-env/edit/main/README.md

 # การติดตั้ง DOSBOX
 1. Download  DOSBOX 
      [https://www.dosbox.com/wiki/Basic_Setup_and_Installation_of_DosBox]
    
 # การติดตั้ง Borland C++
 2. Download โปรแกรม Borland C++ 3.1 & Application Frameworks (3.5).7z
        [https://winworldpc.com/product/borland-c/30]
        - แตกแฟ้ม Borland CPP 3.1 and Application Frameworks (1992) (3.5-1.44mb).7z
        - ใช้โปรแกรม 7z หรือ WinRar แตกแฟ้ม "Disk01.img , Disk02.img ,..., Disk15.img"
          ไปไว้ที่ folder เดียวกันทั้งหมด เช่น DISKALL



        # ติดตั้ง
              MD DISKALL
              CD DISKALL
              INSTALL

        2.1. รายชื่อแฟ้มที่ได้จากการ extract แฟ้ม  ".img"  
   ![image](https://github.com/user-attachments/assets/a13679fb-d213-421c-a84b-5d485f741994)


        2.2. เลือก drive เก็บแฟ้มทั้งหมดของ Borland C++
  ![image](https://github.com/user-attachments/assets/af933041-faed-460b-a208-c57f6e8783ec)


        2.3. folder ที่เก็บแฟ้มทั้งหมดของ Borland C++
 ![image](https://github.com/user-attachments/assets/39d425bb-95cf-4549-aef3-6af81b0be3fc)


        2.4. option ที่ใช้ install
 ![image](https://github.com/user-attachments/assets/0df34462-3793-49b8-afe0-9c647aa99902)


        2.5. กระบวนการ install สำเร็จ
  ![image](https://github.com/user-attachments/assets/6da94d35-e7b4-4179-bafc-841411c50d29)


        2.6. กำหนด Path ใน การ compile
![image](https://github.com/user-attachments/assets/730cc954-542a-4d48-8854-65457c126046)


        

 3. ผลลัพธ์ที่ได้จากการ compile โดย โปรแกรม  "SIMPLELD.EXE"


    ![image](https://github.com/user-attachments/assets/9d0e7456-bec2-42b6-aa94-fd31e4cb9006)





