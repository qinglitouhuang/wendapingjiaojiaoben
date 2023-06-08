var iframe = window.top.document.getElementById('iframeautoheight');
var ifdocument = iframe.contentWindow.document;

var subLength = ifdocument.getElementById("pjkc").options.length - 1;
ifdocument.getElementById("TextBox1").value = "-1";

function execution() {
  var iframe = window.top.document.getElementById('iframeautoheight');
  var ifdocument = iframe.contentWindow.document;

  // 设置教学态度评价选项为"很满意"，除了最后一个选项为"较满意"
  var regTeacher = /^DataGrid1__ctl\d+_JS1$/;
  var selectionsTeacher = ifdocument.querySelectorAll("select[id^='DataGrid1__ctl'][id$='_JS1']");
  for (var i = 0; i < selectionsTeacher.length; i++) {
    var optionCount = selectionsTeacher[i].options.length;
    selectionsTeacher[i].selectedIndex = optionCount - 5; // 设置为倒数第二个选项（"很满意"）
  }
  if (selectionsTeacher.length > 0) {
    var lastTeacherIndex = selectionsTeacher.length - 1;
    selectionsTeacher[lastTeacherIndex].selectedIndex = optionCount - 4; // 设置最后一个选项为"较满意"
  }

  // 设置课程评价内容选项为"很满意"，除了最后一个选项为"较满意"
  var regCourse = /^dgPkc__ctl\d+_kc1$/;
  var selectionsCourse = ifdocument.querySelectorAll("select[name^='dgPkc'][name$=':kc1']");
  for (var i = 0; i < selectionsCourse.length; i++) {
    var optionCount = selectionsCourse[i].options.length;
    selectionsCourse[i].selectedIndex = optionCount - 5; // 设置为倒数第二个选项（"很满意"）
  }
  if (selectionsCourse.length > 0) {
    var lastCourseIndex = selectionsCourse.length - 1;
    selectionsCourse[lastCourseIndex].selectedIndex = optionCount - 4; // 设置最后一个选项为"较满意"
  }

  if (subLength > 1) {
    subLength--;
    ifdocument.getElementById("Button1").click();
  } else {
    ifdocument.getElementById("Button2").click();
  }
}

execution();

iframe.onload = function() {
  if (subLength > 0) {
    execution();
  }
};

