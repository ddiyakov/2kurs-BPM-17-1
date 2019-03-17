set(baza
main.cpp
mainwindow.cpp
mainwindow.h
mainwindow.ui
admin.cpp
admin.h
admin.ui
adlog.cpp
adlog.h
adlog.ui
vocdoc.cpp
vocdoc.h
vocdoc.ui
profile.cpp
profile.h
profile.ui
login.cpp
login.h
login.ui
signup.cpp
signup.h
signup.ui
redact.cpp
redact.h
redact.ui
)

add_executable(BazaVolonterov ${baza})
target_link_libraries(BazaVolonterov Qt5::Widgets)
target_link_libraries(BazaVolonterov Qt5::Core)
target_link_libraries(BazaVolonterov Qt5::Sql)
include_directories(/dll)