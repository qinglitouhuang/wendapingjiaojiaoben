var iframe = window.top.document.getElementById('iframeautoheight');
var ifdocument = iframe.contentWindow.document;

var subLength = ifdocument.getElementById("pjkc").options.length - 1;
ifdocument.getElementById("TextBox1").value = "-1";

function execution() {
  var iframe = window.top.document.getElementById('iframeautoheight');
  var ifdocument = iframe.contentWindow.document;

  // ���ý�ѧ̬������ѡ��Ϊ"������"���������һ��ѡ��Ϊ"������"
  var regTeacher = /^DataGrid1__ctl\d+_JS1$/;
  var selectionsTeacher = ifdocument.querySelectorAll("select[id^='DataGrid1__ctl'][id$='_JS1']");
  for (var i = 0; i < selectionsTeacher.length; i++) {
    var optionCount = selectionsTeacher[i].options.length;
    selectionsTeacher[i].selectedIndex = optionCount - 5; // ����Ϊ�����ڶ���ѡ�"������"��
  }
  if (selectionsTeacher.length > 0) {
    var lastTeacherIndex = selectionsTeacher.length - 1;
    selectionsTeacher[lastTeacherIndex].selectedIndex = optionCount - 4; // �������һ��ѡ��Ϊ"������"
  }

  // ���ÿγ���������ѡ��Ϊ"������"���������һ��ѡ��Ϊ"������"
  var regCourse = /^dgPkc__ctl\d+_kc1$/;
  var selectionsCourse = ifdocument.querySelectorAll("select[name^='dgPkc'][name$=':kc1']");
  for (var i = 0; i < selectionsCourse.length; i++) {
    var optionCount = selectionsCourse[i].options.length;
    selectionsCourse[i].selectedIndex = optionCount - 5; // ����Ϊ�����ڶ���ѡ�"������"��
  }
  if (selectionsCourse.length > 0) {
    var lastCourseIndex = selectionsCourse.length - 1;
    selectionsCourse[lastCourseIndex].selectedIndex = optionCount - 4; // �������һ��ѡ��Ϊ"������"
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

