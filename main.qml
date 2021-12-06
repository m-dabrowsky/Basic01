import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15
import QtQuick.Particles 2.0
import Mike 1.0

Window {
    width: 640
    height: 480
    visible: true
    color: "#ffffff"
    property alias loginButtonText: loginButton.text
    title: qsTr("Hello World")

    property url btnIconSource: "blur.png"
    property color btnColorDefault: "#1c1d20"
    property color btnColorMouseOver: "#23272E"
    property color btnColorClicked: "#00a1f1"

    QtObject{
        id: internal

        // MOUSE OVER AND CLICK CHANGE COLOR
        property var dynamicColor: loginButton.checkable ? "#00a1f1" : "#1c1d20"

    }

    // Przy uzyciu registerType konieczne stworzenie obiektu
    ControlClass {
        id: mikeClass
    }


    Button {
        id: loginButton
        x: 270
        y: 253
        text: qsTr("Click Me!")
        flat: false
        highlighted: false
        onClicked: {
            if (loginButton.checkable == false) {
                // --- Dla qmlRegisterType ---
                mikeClass.doSomething();
                mikeClass.counter = mikeClass.counter + 1
                loginButton.checkable = true;
                loginButton.text =  "Clicked"
            } else if (loginButton.checkable == true) {
                loginButton.checkable = false;
                loginButton.text =  "Click me!"
            }

        }

    }

    Item {
        id: content
        Image {
            id: kropla
            x: 270
            y: 107
            width: 100
            height: 100
            source: btnIconSource
            fillMode: Image.PreserveAspectFit

        }
        ColorOverlay{
            id: overlay
            anchors.fill: kropla
            source: kropla
            color: internal.dynamicColor//loginButton.checkable ? "#00a1f1" : "#1c1d20"

            anchors.verticalCenter: parent.verticalCenter
            antialiasing: true
            width: kropla.width
            height: kropla.height
        }
    }


    Text {
        x: 213
        y: 308
        text: "Global Context Property Counter: " + mikeClass.counter
    }

    ParticleSystem {
        anchors.fill: parent
        ImageParticle {
            source: "blur.png"
        }
        // emit particle object with a size of 20 pixels
        Emitter {
            anchors.fill: parent
            size: 20
            velocity: AngleDirection {
            // Make particles spread out vertically from the bottom
            angle: 270
            // make the movement of the particles slighly different from
            // one another
            angleVariation: 10
            // set speed to 150
            magnitude: 100
            }
        }
    }






}
