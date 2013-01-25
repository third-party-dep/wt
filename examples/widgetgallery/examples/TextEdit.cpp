#include <Wt/Utils>
#include <Wt/WContainerWidget>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WTextEdit>

SAMPLE_BEGIN(TextEdit)

Wt::WContainerWidget *container = new Wt::WContainerWidget();

Wt::WTextEdit *edit = new Wt::WTextEdit(container);
edit->setWidth(200);
edit->setHeight(200);
edit->setText("<p>"
"<span style=\"font-family: 'courier new', courier; font-size: medium;\">"
    "<strong>WTextEdit</strong></span></p>"
"<p>Hey, I'm a&nbsp;<strong>WTextEdit</strong>&nbsp;and you can make me"
    "&nbsp;<span style=\"text-decoration: underline;\"><em>rich</em></span>"
    "&nbsp;by adding your&nbsp;<span style=\"color: #ff0000;\"><em>style</em>"
    "</span>!</p>"
"<p>Other widgets like...</p>"
"<ul style=\"padding: 0px; margin: 0px 0px 10px 25px;\">"
    "<li>WLineEdit</li>"
    "<li>WTextArea</li>"
    "<li>WSpinBox</li>"
"</ul>"
"<p>don't have style.</p>");

Wt::WPushButton *button = new Wt::WPushButton("Get text", container);
button->setMargin(10, Wt::Top);

Wt::WText *out = new Wt::WText(container);
out->setStyleClass("xhtml-output");

button->clicked().connect(std::bind([=] () {
        out->setText("<pre>" + Wt::Utils::htmlEncode(edit->text()) + "</pre>");
}));

SAMPLE_END(return container)
