# MangaShark
#### Video Demo:  <https://www.youtube.com/watch?v=IMInb6ud0TU>
#### Description:
The idea of MangaShark is to be a website where the user can add a manga of his/her taste, if it is not in the database it will already be added, and if already was it will not be added (also showing a flash to the user if the manga is added or not). Allowing users to see the synopsis of this manga and being able to comment (in anonymity) what you think of this manga.
I used in my project sqlite database with a flask extension called SQLAlchemy used to manipulate and add data to the database. In addition, python (flash), javascript, html and css were used.

#### The files in the Project:
layout.html:
    It's the layout of the website, containing inside the base of an html and a navbar
index.html:
    It's the homepage, Where the user will have 3 inputs, 1 to write the name of the manga, 1 text-field to write the synopsis of the manga and the last one is to put the manga banner, which I enabled the user to see a preview of it
mangas.html:
    Where the user can see the list of all mangas added to the database, containing an image (banner) and the title of the manga below. and when clicking on the image, the user will automatically make a POST request, making it render a page only on the specific clicked manga
manga.html:
    It is the page where the user sees the specific manga he clicked on (in the /mangas route), where he can see the title, banner, and synopsis. On this page he can also comment if he wants, in anonymity, about what he thinks about the manga. These comments are saved in a database too
static files:
    Where my css and js was.
app.py:
    Where most of the logic was done