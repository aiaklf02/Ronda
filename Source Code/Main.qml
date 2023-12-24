
import QtQuick
import QtQuick.Controls
import QtMultimedia

Window {
    id:mainWindow
    // 1350 850
    width: 1500
    minimumWidth: 1300
    height: 800
    minimumHeight: 700
    visible: true
    title: qsTr("Jeu De Cartes")


// menu
Rectangle {
            id:espaceMenu
          anchors.fill: parent
          color:'transparent'
          visible:true


          Image {
              id: backgroundimg
              anchors.fill: parent
              source: "images/background.png"
          }

          Image {
              id: startnewGame
              anchors.centerIn: parent
              height: parent.height /3
              fillMode: Image.PreserveAspectFit
              source: "images/commencer.png"
              MouseArea{
                anchors.fill: parent
                onClicked: {
                espaceMenu.visible = false
                espacetable.visible = true
                jeu.demarer_nouveau_jeu();
                }
              }
            }


          Row {
              spacing: 50
              anchors.top: startnewGame.bottom
              anchors.horizontalCenter: startnewGame.horizontalCenter
              Image {
                  id:im1
                  source: "images/f2.png"
                  height: 250
                  fillMode: Image.PreserveAspectFit
                  MouseArea {
                      anchors.fill: parent
                      onClicked:{
                          parent.source = "images/f2.png"
                          im2.source = "images/m1.png"
                          im3.source = "images/d1.png"

                          jeu.changerDificulter(1)
                      }
                  }
              }

              Image {
                  id:im2
                  source: "images/m1.png"
                  height: 250
                  fillMode: Image.PreserveAspectFit
                  MouseArea {
                      anchors.fill: parent
                      onClicked:{
                          parent.source = "images/m2.png"
                          im1.source = "images/f1.png"
                          im3.source = "images/d1.png"

                          jeu.changerDificulter(2)
                      }
                  }
              }

              Image {
                  id:im3
                  source: "images/d1.png"
                  height: 250
                  fillMode: Image.PreserveAspectFit
                  MouseArea {
                      anchors.fill: parent
                      onClicked:{
                          parent.source = "images/d2.png"
                          im1.source = "images/f1.png"
                          im2.source = "images/m1.png"

                          jeu.changerDificulter(3)
                      }
                  }
              }
          }





          }


// table
Rectangle {
            id:espacetable
          anchors.fill: parent
          color:'transparent'
          visible:false

          Image {
              id: backgroundTableimg
              anchors.fill: parent
              source: "images/tablebackground2.jpeg"
          }

          // rectangle de carte masque
          Rectangle{
            id:rectangle_cartemasque
            height: parent.height * 0.33
            width: parent.width * 0.1
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10
            color: "transparent"

            Image {
                id: backImg
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "images/back.png"

            }

            /** annimation **/

            Image {
                id: movingImage
                source: "images/back.png"
               height: parent.height - 50
               width: parent.width
                visible: false


                ParallelAnimation {
                    id: parallelAnim

                    NumberAnimation {
                        target: movingImage
                        property: "x"
                        to: (mainWindow.width/4)+50
                        duration: 600
                        easing.type: Easing.InOutQuad

                    }

                    NumberAnimation {
                        target: movingImage
                        property: "y"
                        to: (mainWindow.height/3)+20
                        duration: 600
                        easing.type: Easing.InOutQuad
                    }
                }

                onVisibleChanged: {
                    if (visible) {
                        movingImage.x = initialX;
                        movingImage.y = initialY;
                        movingImage.visible = true;
                        parallelAnim.start();
                        hideTimer.start();

                    } if (!visible){
                        movingImage.visible = false;
                        movingImage.x = initialX;
                        movingImage.y = initialY;

                    }
                }

                Timer {
                      id: hideTimer
                      interval: 300
                      repeat: false

                      onTriggered: {
                          movingImage.visible = false;
                      }
                  }


                property int initialX: backImg.x
                property int initialY: backImg.y

            }

            Image {
                         id: movingImage2
                         source: "images/back.png"
                        height: parent.height - 50
                        width: parent.width
                         visible: false // Initialement masque

                         ParallelAnimation {
                             id: parallelAnim2

                             NumberAnimation {
                                 target: movingImage2
                                 property: "x"
                                 to: (mainWindow.width/3)+140
                                 duration: 600
                                 easing.type: Easing.InOutQuad

                             }

                             NumberAnimation {
                                 target: movingImage2
                                 property: "y"
                                 to: (mainWindow.height/3)+20
                                 duration: 600
                                 easing.type: Easing.InOutQuad
                             }
                         }

                         onVisibleChanged: {
                             if (visible) {
                                 movingImage2.x = initialX;
                                 movingImage2.y = initialY;
                                 movingImage2.visible = true;
                                 parallelAnim2.start();
                                 hideTimer2.start();

                             } if (!visible){
                                 movingImage2.visible = false;
                                 movingImage2.x = initialX;
                                 movingImage2.y = initialY;

                             }
                         }

                         Timer {
                               id: hideTimer2
                               interval: 300
                               repeat: false

                               onTriggered: {
                                   movingImage2.visible = false;
                               }
                           }


                         property int initialX: backImg.x
                         property int initialY: backImg.y

                     }

            Image {
                         id: movingImage3
                         source: "images/back.png"
                        height: parent.height - 50
                        width: parent.width
                         visible: false

                         ParallelAnimation {
                             id: parallelAnim3

                             NumberAnimation {
                                 target: movingImage3
                                 property: "x"
                                 to: (mainWindow.width/2)+60
                                 duration: 600
                                 easing.type: Easing.InOutQuad

                             }

                             NumberAnimation {
                                 target: movingImage3
                                 property: "y"
                                 to: (mainWindow.height/3)+20
                                 duration: 600
                                 easing.type: Easing.InOutQuad
                             }
                         }

                         onVisibleChanged: {
                             if (visible) {
                                 movingImage3.x = initialX;
                                 movingImage3.y = initialY;
                                 movingImage3.visible = true;
                                 parallelAnim3.start();
                                 hideTimer3.start();

                             } if (!visible){
                                 movingImage3.visible = false;
                                 movingImage3.x = initialX;
                                 movingImage3.y = initialY;

                             }
                         }

                         Timer {
                               id: hideTimer3
                               interval: 300
                               repeat: false

                               onTriggered: {
                                   movingImage3.visible = false;
                               }
                           }

                         property int initialX: backImg.x
                         property int initialY: backImg.y

                     }

            /** fin annimation  **/
          }

           // rectangle de ordinateur
           Rectangle{
            id: rectangle_ordinateur
            width: parent.width * 0.5
            height: parent.height / 3
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            //
            color: "transparent"

            // ce timer , ralenti l executiion de tourne de computer
            Timer {
                   id: computerTimer
                   interval: 1000 // 1000 milliseconds = 1 second
                   repeat: false
                   onTriggered: {
                       jeu.ordinateur();
                   }
               }
            Connections{
            target:jeu
            function onComputerPlay(){
                computerTimer.start();
                }
            }

             /* emplacement des cartes */
            Row {
                anchors.fill: parent
                anchors.leftMargin: 60
                spacing: 60 // Set the spacing between images

                Image {
                    id: carte4
                    width: 150
                    anchors.verticalCenter: parent.verticalCenter
                    height: parent.height*0.7
                    fillMode: Image.PreserveAspectFit
                    source: ""
                }

                Image {
                    id: carte5
                    width: 150
                    anchors.verticalCenter: parent.verticalCenter
                    fillMode: Image.PreserveAspectFit
                    height: parent.height*0.7
                    source: ""
                }

                Image {
                    id:carte6
                    width: 150
                    anchors.verticalCenter: parent.verticalCenter
                    fillMode: Image.PreserveAspectFit
                    height: parent.height*0.7
                    source: ""
                }
            Connections{
            target: j2
            function onCartesMainChanged(){
                clickaudio.play();
                let nmbrCartes = j2.nmbrCartesMain();

                    if (nmbrCartes === 1){
                        carte4.source="images/back.png"
                        carte5.source="";
                        carte6.source="";
                         }
                    else if(nmbrCartes === 2){
                        carte4.source="images/back.png"
                        carte5.source="images/back.png"
                        carte6.source="";

                    }
                    else if(nmbrCartes === 3){
                        carte4.source="images/back.png"
                        carte5.source="images/back.png"
                        carte6.source="images/back.png"

                    }

                }

            }


            }


           }
           /* rectangle de carte obtenue par ordinateur*/
            Rectangle{
            id: c_obtenue_ordinateur
            anchors.left: rectangle_ordinateur.right
            anchors.right: parent.right
            anchors.top: parent.top
            height: parent.height/3
            color: "transparent"
            Image {
                id: carte_obtunue_par_ordinateur
                height: parent.height * 0.7
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                fillMode: Image.PreserveAspectFit
                source: "images/back.png"
            }

            }


           // rectangle de table
           // horizontal list view
            Rectangle{
                id:rectangle_table
                height: parent.height/3
                width: parent.width*0.5
                anchors{
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter
                }
                color: "transparent"

                ListView{
                    id:ltsview
                    width: parent.width
                    height: parent.height
                    orientation: ListView.Horizontal
                    spacing:10

                    model: ListModel {
                              id: computerSide
//                               ListElement { Nom_Carte: "COIN" ; Numero_Carte:1 ; imagesource:"images/back.png" }

                    }

                    delegate: Item {
                               width: 160
                               height: 250
                               anchors.verticalCenter: parent.verticalCenter

                               Image {
                                   id: cartes
                                   anchors.fill: parent
                                   fillMode: Image.PreserveAspectFit
                                   source: model.imagesource

                               }


                                }

                }


                Connections{
                target:Table
                function onCartestableChanged(){
                    delai_de_Table.start();

                    }

                }

                Timer {
                                      id: delai_de_Table
                                      interval: 300 // Timer interval in milliseconds
                                      repeat: false // Run the timer only once

                                      onTriggered: {

                                          let taille_de_table = Table.table_taille();

                                          computerSide.clear();
                                          for (x = 0; x < taille_de_table;x++){
                                                              computerSide.append( { imagesource: Table.imagedeCarteenTableParIndex(x)} );
                                          }


                                      }
                                  }

            }


           // rectangel de joueur
           Rectangle{
               id:rectangle_joeur
               width: parent.width * 0.5
               height: parent.height/3
               anchors.bottom: parent.bottom
               anchors.horizontalCenter: parent.horizontalCenter
               color: "transparent"

                        /* emplacement des cartes*/

               Row {
                   id:cartrow
                   anchors.fill: parent
                   anchors.leftMargin: 60
                   spacing: 60 // Set the spacing between images

                   Image {
                       id:carte1
                       width: 150
                       anchors.verticalCenter: parent.verticalCenter
                       height: parent.height*0.7
                       fillMode: Image.PreserveAspectFit
                       source: ""

                       property int numero_Carte;
                       property string nom_Carte;
                       property string imagesource;

                       MouseArea{
                            anchors.fill: parent
                            onEntered: {
                                parent.scale = 0.5
                            }
                                onExited: {
                                    if(j1.what_is_MonTour()){
                                    parent.visible= false
                                    }
                                    parent.scale = 1

                                    // ici on doit executer la fonction de click du joueur
                                    jeu.clicksurcartes(carte1.numero_Carte,carte1.nom_Carte.toString());

                                }
                            }
                   }

                   Image {
                       id:carte2
                       width: 150
                       anchors.verticalCenter: parent.verticalCenter
                       fillMode: Image.PreserveAspectFit
                       height: parent.height*0.7
                       source: ""

                       property int numero_Carte;
                       property string nom_Carte;
                       property string imagesource;

                       MouseArea{
                            anchors.fill: parent
                            onEntered: {
                                parent.scale = 0.5
                            }
                                onExited: {
                                    if(j1.what_is_MonTour()){
                                    parent.visible= false
                                    }
                                    parent.scale = 1

                                    // ici on doit executer la fonction de click du joueur
                                    jeu.clicksurcartes(carte2.numero_Carte,carte2.nom_Carte.toString());

                                }
                            }

                   }

                   Image {
                       id:carte3
                       width: 150
                       anchors.verticalCenter: parent.verticalCenter
                       fillMode: Image.PreserveAspectFit
                       height: parent.height*0.7
                       source: ""

                              property int numero_Carte;
                              property string nom_Carte;
                              property string imagesource;

                       MouseArea{
                            anchors.fill: parent
                            onEntered: {
                                parent.scale = 1.2
                            }
                                onExited: {
                                    if(j1.what_is_MonTour()){
                                    parent.visible= false
                                        }
                                    parent.scale = 1

                                    /* here i will call cpp function to send this card to table*/
                                    jeu.clicksurcartes(carte3.numero_Carte,carte3.nom_Carte.toString());
                                }
                            }

                   }

               }

               Connections{
               target: j1
                function onCartesMainChanged(){
                    clickaudio.play();
                    delaidesCartes.start();
                    }


                }
               Timer{
               id :delaidesCartes
               interval:300
               repeat: false
               onTriggered: {
                afficher();
               }


               function afficher(){

                   let nmbrCartes = j1.nmbrCartesMain();

                   cartrow.children[0].visible = false;
                   cartrow.children[0].numero_Carte = -1;
                   cartrow.children[0].nom_Carte = "";
                   cartrow.children[0].imagesource = "";
                   cartrow.children[0].source = "";


                   cartrow.children[1].visible = false;
                   cartrow.children[1].numero_Carte = -1;
                   cartrow.children[1].nom_Carte = "";
                   cartrow.children[1].imagesource = "";
                   cartrow.children[1].source = "";

                   cartrow.children[2].visible = false;
                   cartrow.children[2].numero_Carte = -1;
                   cartrow.children[2].nom_Carte = "";
                   cartrow.children[2].imagesource = "";
                   cartrow.children[2].source = "";

                   for(var i=0; i< nmbrCartes ; i++){
                      var imgrect = cartrow.children[i];

                       imgrect.numero_Carte = j1.numero_de_Carteparindex(i);
                       imgrect.nom_Carte = j1.nom_de_CartCarteparindex(i);
                       imgrect.imagesource = j1.imgCarteparindex(i);
                       imgrect.source = j1.imgCarteparindex(i);
                       imgrect.visible = true;
               }

               }
   }

           }
           /* rectangle de carte obtenue par ordinateur*/
           Rectangle{
             id: c_obtenue_Joeur
               anchors.left: rectangle_joeur.right
               anchors.right: parent.right
               anchors.bottom: parent.bottom
               height: parent.height/3
               color: "transparent"
               Image {
                             id: carte_obtunue_par_joueur
                             height: parent.height * 0.7
                             anchors.verticalCenter: parent.verticalCenter
                             anchors.horizontalCenter: parent.horizontalCenter
                             fillMode: Image.PreserveAspectFit
                             source: "images/back.png"
                         }

           }



Connections{
target:jeu
function onAnnimationDestributionChanged(){
    movingImage.visible = true;
    movingImage2.visible = true;
    movingImage3.visible = true;
    delaidesCartes.start();

}

}

}


// gagnant
Rectangle {
            id: gagnantEspace
          anchors.fill: parent
          color: "silver"
          visible:false

            AnimatedImage {
                id: animation
                anchors.fill: parent
                source: "images/EkA5.gif"
            }
          /***/
          Column {
              width: parent.width
              spacing: 60  // Adjust the spacing between rows if needed
              anchors.verticalCenter: parent.verticalCenter
              anchors.horizontalCenter: parent.horizontalCenter

              Row {
                  id: j1Score
                  anchors.horizontalCenter: parent.horizontalCenter
                  Image {
                      id: imgstarj1
                      height: 40
                      width: 40
                      source: "images/Golden_star.png"
                  }
                  Text {
                      id: scorej1
                       anchors.left: imgstarj1
                      text: "Premier classement : "
                      color: "white"
                      font.pixelSize: 30
                      font.bold: true

                  }
                  Text {
                      id: scorej11
                      anchors.left: scorej1
                      text: "."
                      color: "gold"
                      font.pixelSize: 35
                      font.bold: true

                  }
              }

              Row {
                  // Another row similar to the one above
                  id: anotherRow
                  anchors.horizontalCenter: parent.horizontalCenter
                  Image {
                      id: imgStarscorej2
                      height: 40
                      width: 40
                      source: "images/Silver_star.png"
                  }

                  Text {
                      id: anotherScorej1
                      anchors.left:  imgStarscorej2
                      text: "Deuxieme classement : "
                      color: "white"
                      font.pixelSize: 30
                      font.bold: true
                  }
                  Text {
                      id: anotherScorej11
                      anchors.left: anotherScorej1
                      text: "."
                      color: "silver"
                      font.pixelSize: 35
                      font.bold: true
                  }
              }

              Row{
                id:scorepanel
                width: parent.width*0.8
                spacing: 40
                anchors.horizontalCenter: parent.horizontalCenter

                Column {
                    spacing: 10  // Adjust the spacing between rows if needed
                    width: parent.width/2
                    Text {
                        id: frstposition
                        text: "Votre Score"
                        font.pixelSize: 40
                        font.bold: true
                        color: "white"
                    }
                    Row {
                        id: row1
                        Text {
                            id: text1_1
                            text: "Nombre de cartes obtenues: "
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"

                        }
                        Text {
                            id: text1_2
                            anchors.left: text1_1
                            text: "x"
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                    }

                    Row {
                        id: row2
                        Text {
                            id: text2_1
                            text: "Points de partie: "
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                        Text {
                            id: text2_2
                            anchors.left: text2_1
                            text: "x"
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                    }

                    Row {
                        id: row22
                        Text {
                            id: total
                            text: "Totale: "
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                        Text {
                            id: totaltext
                            anchors.left: total
                            text: "x"
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                    }

                    // Add more rows as needed
                }



                Column {
                    spacing: 10  // Adjust the spacing between rows if needed
                    width: parent.width/2

                    Text {
                        id: secondposition
                        text: "Score d'Ordinateur"
                        font.pixelSize: 40
                        font.bold: true
                        color: "white"
                    }
                    Row {
                        id: row3
                        Text {
                            id: text3_1
                            text: "Nombre de cartes obtenues: "
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                        Text {
                            id: text3_2
                            anchors.left: text3_1
                            text: "x"
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                    }

                    Row {
                        id: row4
                        Text {
                            id: text4_1
                            text: "Points de partie: "
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                        Text {
                            id: text4_2
                            anchors.left: text4_1
                            text: "x"
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                    }

                    Row {
                        id: row223
                        Text {
                            id: total2
                            text: "Totale: "
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                        Text {
                            id: totaltext2
                            anchors.left: total2
                            text: "x"
                            font.pixelSize: 30
                            font.bold: true
                            color: "white"
                        }
                    }


                }// fin column 2


              }

              Row {
                  anchors.horizontalCenter: parent.horizontalCenter
                  Image {
                      id: bouttontomenu
                      source: "images/MENU.png"
                      height: 150
                      fillMode: Image.PreserveAspectFit
                      MouseArea{
                      anchors.fill: parent
                      onClicked: {
                              espaceMenu.visible = true;
                              gagnantEspace.visible = false
                      }
                      }
                  }

                  Image {
                      id: playagainbutton
                      source: "images/rejouer.png"
                      height: 150
                      fillMode: Image.PreserveAspectFit
                      MouseArea{
                      anchors.fill: parent
                      onClicked: {
                      /* play again*/
                          gagnantEspace.visible = false
                          espacetable.visible = true
                          jeu.demarer_nouveau_jeu();

                      }
                      }
                  }

              }

          }

          /****/

            Connections{
            target: jeu
            function onFin_jeuChanged(){
                    /* hna khass n3emer les case b les valuer dialom */

                let nbrcarteobtenueordi = jeu.getnombrecarteObtenueOrdinateur();
                text3_2.text = nbrcarteobtenueordi;

                let pointdordinateur = jeu.getScoreOrdinateur();
                text4_2.text = pointdordinateur;

                let totalComp = nbrcarteobtenueordi + pointdordinateur;
                totaltext2.text = totalComp;

                let nbrcarteobtenueJ = jeu.getnombrecarteObtenueJoeur();
                text1_2.text = nbrcarteobtenueJ;

                let pointdejoeur = jeu.getScoreJoueur();
                text2_2.text = pointdejoeur;

                let totalJoueur = nbrcarteobtenueJ + pointdejoeur;
                totaltext.text = totalJoueur;

                if(totalJoueur < totalComp){
                anotherScorej11.text = "Vous"
                scorej11.text = "Ordinateur"
                }else {
                    anotherScorej11.text = "Ordinateur"
                    scorej11.text = "Vous"
                }

                    espacetable.visible = false
                    gagnantEspace.visible = true

                }
            }
}



SoundEffect {
    id: clickaudio
    source: "audio/click.wav"
}
/**/
}

