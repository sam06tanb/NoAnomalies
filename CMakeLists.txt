cmake_minimum_required(VERSION 3.30) # A sua versão era 3.30, pode manter. 3.20 é uma boa base.
project(AEDTrabalho C)

set(CMAKE_C_STANDARD 11)

# Sua configuração para encontrar e carregar a Raylib (está ótima, não mude)
include(FetchContent)
function(include_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG ${gitTag}
            GIT_SHALLOW TRUE
            GIT_PROGRESS TRUE
    )
    FetchContent_MakeAvailable(${libName})
endfunction()

set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.0) # Corrigi para https://
endif ()


# Lista de todos os seus arquivos fonte.
# Manter assim manualmente funciona, mas lembre-se de adicionar novos arquivos .c aqui!
add_executable(AEDTrabalho
        MENU/C/main.c
        MENU/C/jogo_estado.c
        MENU/C/menu_screen.c
        MENU/POPUP/popup_opcoes.c
        MENU/POPUP/slider_volume.c
        MENU/POPUP/aplicar.c
        MENU/POPUP/ui_helpers.c
        MENU/POPUP/seletor_resolucao.c
        MENU/POPUP/botao_fechar.c
        MENU/POPUP/botao_tutorial.c
        MENU/InGAME/game_screen.c
        MENU/C/DescCarreg.c
        MENU/InGAME/extraObject.c
        MENU/InGAME/hour.c
        MENU/InGAME/intruder.c
        MENU/InGAME/missingObject.c
        MENU/InGAME/objectMovement.c
        MENU/InGAME/report.c
        MENU/InGAME/RoomChange.c
        MENU/InGAME/livingRoom.c
        MENU/InGAME/bedRoom.c
        MENU/InGAME/botaoVoltar.c
        MENU/InGAME/painel_reporte.c)

# --- A CORREÇÃO PRINCIPAL ESTÁ AQUI ---
# Informa ao compilador TODAS as pastas onde ele pode encontrar arquivos .h
target_include_directories(AEDTrabalho PRIVATE
        ${raylib_INCLUDE_DIRS}
        "MENU/H"
        "MENU/InGAME"
        "MENU/POPUP"
        "MENU/C"
)

# Linka o seu projeto com a biblioteca Raylib
target_link_libraries(AEDTrabalho PRIVATE ${LIB1})