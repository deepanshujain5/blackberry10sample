// Default empty project template
import bb.cascades 1.0

TabbedPane {
    attachedObjects: [
        ComponentDefinition {
            id: tab1DetailPage
            source: "tab1DetailPage.qml"
        },
        ComponentDefinition {
            id: tab2DetailPage
            source: "tab2DetailPage.qml"
        }
    ]
    Tab {
        title: qsTr("Tab1")
        id: tab1
        Page {
            Container {
                background: pageBg.imagePaint
                layout: StackLayout {
                    orientation: LayoutOrientation.TopToBottom
                }
            }
        }
    }
    Tab {
        id: tab2
        title: qsTr("Tab2")

        NavigationPane {
            id: tab1NavigationPane
            Page {
                Container {
                    Button {
                        id: searchBtn
                        text: "NextPage"
                        verticalAlignment: VerticalAlignment.Center
                        onClicked: {
                            var newPage = tab1DetailPage.createObject();
                            tab1NavigationPane.push(newPage);
                        }
                    }

                }
            }

        }
    }
    Tab {
        id: tab3
        title: qsTr("Tab3")
        content: NavigationPane {
            id : tab2NavigationPane
            Page {
                Container {
                    Button {
                        text: "DetailPage"
                        verticalAlignment: VerticalAlignment.Center
                        onClicked: {
                            var newPage = tab2DetailPage.createObject();
                            tab2NavigationPane.push(newPage);
                        }
                    }
                }

            }

        }
    }

    onCreationCompleted: {
        // this slot is called when declarative scene is created
        // write post creation initialization here
        console.log("TabbedPane - onCreationCompleted()")

        // enable layout to adapt to the device rotation
        // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
        OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
    }
}
