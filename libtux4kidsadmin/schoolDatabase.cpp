#include "schoolDatabase.h"
#include "schoolDatabase_p.h"
#include "class.h"
#include "teacher.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QVariant>
#include <QStringList>

/*********************** SchoolDatabasePrivate ***********************/

SchoolDatabasePrivate::SchoolDatabasePrivate()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
}

SchoolDatabasePrivate::~SchoolDatabasePrivate()
{
	db.close();
}

void SchoolDatabasePrivate::createTables()
{
	error = false;
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery createClasses("CREATE TABLE classes (id integer primary key, name text);", db);
	if (!createClasses.isActive()) {
		error = true;
		lastError = createClasses.lastError().text();
		return;
	}

	QSqlQuery createTeachers("CREATE TABLE teachers (id integer primary key, first_name text, last_name text);", db);
	if (!createClasses.isActive()) {
		error = true;
		lastError = createTeachers.lastError().text();
		return;
	}

	QSqlQuery createStudents("CREATE TABLE students (id integer primary key, profile_name text);", db);
	if (!createStudents.isActive()) {
		error = true;
		lastError = createStudents.lastError().text();
		return;
	}

	QSqlQuery createClassTeachers("CREATE TABLE class_teachers "
			"(id_class integer CONSTRAINT fk_id_class REFERENCES classes(id) ON DELETE CASCADE,"
			"id_teacher integer CONSTRAINT fk_id_teacher REFERENCES teachers(id) ON DELETE CASCADE,"
			"primary key(id_class,id_teacher));", db);
	if (!createClassTeachers.isActive()) {
		error = true;
		lastError = createClassTeachers.lastError().text();
		return;
	}

	QSqlQuery createClassStudents("CREATE TABLE class_students "
			"(id_class integer CONSTRAINT fk_id_class REFERENCES classes(id) ON DELETE CASCADE, "
			"id_student integer CONSTRAINT fk_id_student REFERENCES students(id) ON DELETE CASCADE,"
			"primary key(id_class,id_student));", db);
	if (!createClassStudents.isActive()) {
		error = true;
		lastError = createClassStudents.lastError().text();
		return;
	}
}

void SchoolDatabasePrivate::createTriggers()
{
	error = false;
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery createTrigger1("DROP TRIGGER fki_class_teachers_id_class_classes_id;"
				 "CREATE TRIGGER fki_class_teachers_id_class_classes_id"
				 "BEFORE INSERT ON [class_teachers]"
				 "FOR EACH ROW BEGIN"
				 "SELECT RAISE(ROLLBACK, \'insert on table"
				 "class_teachers\" violates foreign key constraint"
				 "fki_class_teachers_id_class_classes_id\"')"
	"WHERE NEW.id_class IS NOT NULL AND (SELECT id FROM classes WHERE id = NEW.id_class) IS NULL;" \
		"END;", db);
	if (!createTrigger1.isActive()) {
		error = true;
		lastError = createTrigger1.lastError().text();
		return;
	}

	QSqlQuery createTrigger2("DROP TRIGGER fku_class_teachers_id_class_classes_id;"
				"CREATE TRIGGER fku_class_teachers_id_class_classes_id"
				"BEFORE UPDATE ON [class_teachers]"
				"FOR EACH ROW BEGIN"
				"SELECT RAISE(ROLLBACK, 'update on table\" class_teachers\" violates foreign key constraint \"fku_class_teachers_id_class_classes_id\"')"
				"WHERE NEW.id_class IS NOT NULL AND (SELECT id FROM classes WHERE id = NEW.id_class) IS NULL;"
				"END;", db);
	if (!createTrigger2.isActive()) {
		error = true;
		lastError = createTrigger2.lastError().text();
		return;
	}

	QSqlQuery createTrigger3("DROP TRIGGER fkdc_class_teachers_id_class_classes_id;"
				"CREATE TRIGGER fkdc_class_teachers_id_class_classes_id"
				"BEFORE DELETE ON classes"
				"FOR EACH ROW BEGIN"
				"DELETE FROM class_teachers WHERE class_teachers.id_class = OLD.id;"
				"END;", db);
	if (!createTrigger3.isActive()) {
		error = true;
		lastError = createTrigger3.lastError().text();
		return;
	}

	QSqlQuery createTrigger4("DROP TRIGGER fki_class_teachers_id_teacher_teachers_id;"
			"CREATE TRIGGER fki_class_teachers_id_teacher_teachers_id"
			"BEFORE INSERT ON [class_teachers]"
			"FOR EACH ROW BEGIN"
			"SELECT RAISE(ROLLBACK, 'insert on table \"class_teachers\" violates foreign key constraint \"fki_class_teachers_id_teacher_teachers_id\"')"
			"WHERE NEW.id_teacher IS NOT NULL AND (SELECT id FROM teachers WHERE id = NEW.id_teacher) IS NULL;"
			"END;", db);
	if (!createTrigger4.isActive()) {
		error = true;
		lastError = createTrigger4.lastError().text();
		return;
	}

	QSqlQuery createTrigger5("DROP TRIGGER fku_class_teachers_id_teacher_teachers_id;"
			"CREATE TRIGGER fku_class_teachers_id_teacher_teachers_id"
			"BEFORE UPDATE ON [class_teachers]"
			"FOR EACH ROW BEGIN"
			"SELECT RAISE(ROLLBACK, 'update on table \"class_teachers\" violates foreign key constraint \"fku_class_teachers_id_teacher_teachers_id\"')"
			"WHERE NEW.id_teacher IS NOT NULL AND (SELECT id FROM teachers WHERE id = NEW.id_teacher) IS NULL;"
			"END;", db);
	if (!createTrigger5.isActive()) {
		error = true;
		lastError = createTrigger5.lastError().text();
		return;
	}

	QSqlQuery createTrigger6("DROP TRIGGER fkdc_class_teachers_id_teacher_teachers_id;"
			"CREATE TRIGGER fkdc_class_teachers_id_teacher_teachers_id"
			"BEFORE DELETE ON teachers"
			"FOR EACH ROW BEGIN"
			"DELETE FROM class_teachers WHERE class_teachers.id_teacher = OLD.id;"
			"END;", db);
	if (!createTrigger6.isActive()) {
		error = true;
		lastError = createTrigger6.lastError().text();
		return;
	}

	QSqlQuery createTrigger7("DROP TRIGGER fki_class_students_id_class_classes_id;"
			"CREATE TRIGGER fki_class_students_id_class_classes_id"
			"BEFORE INSERT ON [class_students]"
			"FOR EACH ROW BEGIN"
			"SELECT RAISE(ROLLBACK, 'insert on table \"class_students\" violates foreign key" "constraint \"fki_class_students_id_class_classes_id\"')"
			"WHERE NEW.id_class IS NOT NULL AND (SELECT id FROM classes WHERE id = NEW.id_class) IS NULL;"
			"END;", db);
	if (!createTrigger7.isActive()) {
		error = true;
		lastError = createTrigger7.lastError().text();
		return;
	}

	QSqlQuery createTrigger8("DROP TRIGGER fku_class_students_id_class_classes_id;"
			"CREATE TRIGGER fku_class_students_id_class_classes_id"
			"BEFORE UPDATE ON [class_students]"
			"FOR EACH ROW BEGIN"
			"SELECT RAISE(ROLLBACK, 'update on table \"class_students\" violates foreign key constraint \"fku_class_students_id_class_classes_id\"')"
			"WHERE NEW.id_class IS NOT NULL AND (SELECT id FROM classes WHERE id = NEW.id_class) IS NULL;"
			"END;", db);
	if (!createTrigger8.isActive()) {
		error = true;
		lastError = createTrigger8.lastError().text();
		return;
	}

	QSqlQuery createTrigger9("DROP TRIGGER fkdc_class_students_id_class_classes_id;"
			"CREATE TRIGGER fkdc_class_students_id_class_classes_id"
			"BEFORE DELETE ON classes"
			"FOR EACH ROW BEGIN"
			"DELETE FROM class_students WHERE class_students.id_class =OLD.id;"
			"END;", db);
	if (!createTrigger9.isActive()) {
		error = true;
		lastError = createTrigger9.lastError().text();
		return;
	}

	QSqlQuery createTrigger10("DROP TRIGGER fki_class_students_id_student_students_id;"
			"CREATE TRIGGER fki_class_students_id_student_students_id"
			"BEFORE INSERT ON [class_students]"
			"FOR EACH ROW BEGIN"
			"SELECT RAISE(ROLLBACK, 'insert on table \"class_students\" violates foreign key constraint \"fki_class_students_id_student_students_id\"')"
			"WHERE NEW.id_student IS NOT NULL AND (SELECT id FROM students WHERE id = NEW.id_student) IS NULL;"
			"END;", db);
	if (!createTrigger10.isActive()) {
		error = true;
		lastError = createTrigger10.lastError().text();
		return;
	}

	QSqlQuery createTrigger11("DROP TRIGGER	fku_class_students_id_student_students_id;"
			"CREATE TRIGGER fku_class_students_id_student_students_id"
			"BEFORE UPDATE ON [class_students]"
			"FOR EACH ROW BEGIN"
			"SELECT RAISE(ROLLBACK, 'update on table \"class_students\" violates foreign key constraint \"fku_class_students_id_student_students_id\"')"
			"WHERE NEW.id_student IS NOT NULL AND (SELECT id FROM students WHERE id = NEW.id_student) IS NULL;"
			"END;", db);
	if (!createTrigger11.isActive()) {
		error = true;
		lastError = createTrigger11.lastError().text();
		return;
	}

	QSqlQuery createTrigger12("DROP TRIGGER fkdc_class_students_id_student_students_id;"
			"CREATE TRIGGER fkdc_class_students_id_student_students_id"
			"BEFORE DELETE ON students"
			"FOR EACH ROW BEGIN"
			"DELETE FROM class_students WHERE class_students.id_student = OLD.id;"
			"END;", db);
	if (!createTrigger12.isActive()) {
		error = true;
		lastError = createTrigger12.lastError().text();
		return;
	}
}

void SchoolDatabasePrivate::addClass(Class &newClass)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}
	QSqlQuery insertClass;

	error = false;

	insertClass.prepare("INSERT INTO classes(name) VALUES(:name);");
	insertClass.bindValue(":name", newClass.name());
	insertClass.exec();

	if (!insertClass.isActive()) {
		error = true;
		lastError = insertClass.lastError().text();
		return;
	} else {


		QSqlQuery getClassId;
		getClassId.prepare("SELECT MAX(id) FROM classes;");
		getClassId.exec();

		if (!getClassId.isActive()) {
			error = true;
			lastError = getClassId.lastError().text();
			return;
		}

		if (!getClassId.first()){
			error = true;
			lastError = getClassId.lastError().text();
			return;
		} else {
			newClass.setId(getClassId.value(0).toInt());
			Q_Q(SchoolDatabase);
			emit q->classAdded(newClass);
		}
		getClassId.finish();

		db.transaction();
		if (addClassTeachers(newClass)) {
			addClassStudents(newClass);
			db.commit();
		}
	}
}

bool SchoolDatabasePrivate::addClassTeachers(Class &newClass)
{
	foreach (Teacher teacher, *newClass.teachers()) {
		QSqlQuery addTeacher;
		addTeacher.prepare("INSERT INTO class_teachers(id_class, id_teacher) VALUES(:id_class, :id_teacher);");
		addTeacher.bindValue(":id_class", newClass.id());
		addTeacher.bindValue(":id_teacher", teacher.id());
		addTeacher.exec();
		if (!addTeacher.isActive()) {
			error = true;
			lastError = addTeacher.lastError().text();
			return false;
		}
	}

	return true;
}

bool SchoolDatabasePrivate::addClassStudents(Class &newClass)
{
	foreach (QString studentDirName, *newClass.students()) {
		QSqlQuery findStudentId;
		findStudentId.prepare("SELECT id FROM students WHERE profile_name = :profile_name;");
		findStudentId.bindValue(":profileName", studentDirName);
		findStudentId.exec();
		if (!findStudentId.isActive()) {
			error = true;
			lastError = findStudentId.lastError().text();
			return false;
		}
		if (!findStudentId.first()) {
			error = true;
			lastError = "Multiple profile_name-s in database";
			return false;
		}
		int studentId = findStudentId.value(0).toInt();
		findStudentId.finish();

		QSqlQuery addStudent;
		addStudent.prepare("INSERT INTO class_students(id_class, id_student) VALUES(:id_class, :id_student);");
		addStudent.bindValue(":id_class", newClass.id());
		addStudent.bindValue(":id_student", studentId);
		addStudent.exec();
		if (!addStudent.isActive()) {
			error = true;
			lastError = addStudent.lastError().text();
			return false;
		}
	}

	return true;
}

void SchoolDatabasePrivate::updateClass(Class &updatedClass)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery updateClass;

	error = false;

	updateClass.prepare("UPDATE classes SET name = :name WHERE id = :id;");
	updateClass.bindValue(":name", updatedClass.name());
	updateClass.bindValue(":id", updatedClass.id());
	updateClass.exec();

	if (!updateClass.isActive()) {
		error = true;
		lastError = updateClass.lastError().text();
		return;
	}

	Q_Q(SchoolDatabase);
	emit q->classUpdated(updatedClass);
}

void SchoolDatabasePrivate::deleteClass(Class &deletedClass)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery deleteClass;

	error = false;

	deleteClass.prepare("DELETE FROM classes WHERE id = :id;");
	deleteClass.bindValue(":id", deletedClass.id());
	deleteClass.exec();

	if (!deleteClass.isActive()) {
		error = true;
		lastError = deleteClass.lastError().text();
		return;
	}

	Q_Q(SchoolDatabase);
	emit q->classDeleted(deletedClass);
}

void SchoolDatabasePrivate::addTeacher(Teacher &newTeacher)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}
	QSqlQuery insertTeacher;

	error = false;

	insertTeacher.prepare("INSERT INTO teacher(first_name, last_name) VALUES(:first_name, :last_name);");
	insertTeacher.bindValue(":first_name", newTeacher.firstName());
	insertTeacher.bindValue(":last_name", newTeacher.lastName());
	insertTeacher.exec();

	if (!insertTeacher.isActive()) {
		error = true;
		lastError = insertTeacher.lastError().text();
		return;
	} else {
		QSqlQuery getTeacherId;
		getTeacherId.prepare("SELECT MAX(id) FROM teachers;");
		getTeacherId.exec();

		if (!getTeacherId.isActive()) {
			error = true;
			lastError = getTeacherId.lastError().text();
			return;
		}

		if (!getTeacherId.first()){
			error = true;
			lastError = getTeacherId.lastError().text();
			return;
		} else {
			newTeacher.setId(getTeacherId.value(0).toInt());
			Q_Q(SchoolDatabase);
			emit q->teacherAdded(newTeacher);
		}
	}
}

void SchoolDatabasePrivate::updateTeacher(Teacher &updatedTeacher)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery updateTeacher;

	error = false;

	updateTeacher.prepare("UPDATE teachers SET first_name = :first_name, last_name = :last_name WHERE id = :id;");
	updateTeacher.bindValue(":first_name", updatedTeacher.firstName());
	updateTeacher.bindValue(":last_name", updatedTeacher.lastName());
	updateTeacher.bindValue(":id", updatedTeacher.id());
	updateTeacher.exec();

	if (!updateTeacher.isActive()) {
		error = true;
		lastError = updateTeacher.lastError().text();
		return;
	}

	Q_Q(SchoolDatabase);
	emit q->teacherUpdated(updatedTeacher);
}

void SchoolDatabasePrivate::deleteTeacher(Teacher &deletedTeacher)
{
	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return;
	}

	QSqlQuery deleteTeacher;

	error = false;

	deleteTeacher.prepare("DELETE FROM teachers WHERE id = :id");
	deleteTeacher.bindValue(":id", deletedTeacher.id());
	deleteTeacher.exec();

	if (!deleteTeacher.isActive()) {
		error = true;
		lastError = deleteTeacher.lastError().text();
		return;
	}

	Q_Q(SchoolDatabase);
	emit q->teacherDeleted(deletedTeacher);
}

QList<Class> SchoolDatabasePrivate::classList() const
{
	QList<Class> result;

	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return result;
	}

	QSqlQuery classList;

	error = false;

	classList.prepare("SELECT name FROM classes;");
	classList.exec();

	if (!classList.isActive()) {
		error = true;
		lastError = classList.lastError().text();
		return result;
	}

	QSqlRecord classRec = classList.record();

	while (classList.next()) {
		int id = classList.value(classRec.indexOf("id")).toInt();
		QString name = classList.value(classRec.indexOf("name")).toString();
		Class newClass;
		newClass.setId(id);
		newClass.setName(name);
		result.append(newClass);
	}
	return result;
}

QList<Teacher> SchoolDatabasePrivate::teacherList() const
{
	QList<Teacher> result;

	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return result;
	}

	QSqlQuery teacherList;

	error = false;

	teacherList.prepare("SELECT id, first_name, last_name FROM teachers;");
	teacherList.exec();

	if (!teacherList.isActive()) {
		error = true;
		lastError = teacherList.lastError().text();
		return result;
	}

	QSqlRecord teacherRec = teacherList.record();

	while (teacherList.next()) {
		int id = teacherList.value(teacherRec.indexOf("id")).toInt();
		QString firstName = teacherList.value(teacherRec.indexOf("first_name")).toString();
		QString lastName = teacherList.value(teacherRec.indexOf("last_name")).toString();
		Teacher newTeacher(firstName, lastName);
		newTeacher.setId(id);
		//newTeacher.setFirstName(firstName);
		//newTeacher.setLastName(lastName);
		result.append(newTeacher);
	}
	return result;
}

void SchoolDatabasePrivate::synchronizeStudents(const QList< QPointer<StudentDir> > &studentsList)
{
	QStringList existingStudents;

	foreach(StudentDir *studentDir, studentsList) {
		existingStudents.append(studentDir->dirName());
	}

	QStringList databaseStudents = studentList();

	QStringList toAddStudents = existingStudents;
	foreach(QString profileName, databaseStudents) {
		toAddStudents.removeOne(profileName);
	}
	qDebug() << toAddStudents;
	QStringList toDeleteStudents = databaseStudents;
	foreach(QString profileName, existingStudents) {
		toDeleteStudents.removeOne(profileName);
	}

	db.transaction();

	foreach(QString profileName, toAddStudents) {
		QSqlQuery addStudent;
		addStudent.prepare("INSERT INTO students(profile_name) VALUES(:profile_name);");
		addStudent.bindValue(":profile_name", profileName);
		addStudent.exec();
		if (!addStudent.isActive()) {
			error = true;
			lastError = addStudent.lastError().text();
			return;
		}
	}

	foreach(QString profileName, toDeleteStudents) {
		QSqlQuery deleteStudent;
		deleteStudent.prepare("DELETE FROM students WHERE profile_name = :profile_name;");
		deleteStudent.bindValue(":profile_name", profileName);
		deleteStudent.exec();

		if (!deleteStudent.isActive()) {
			error = true;
			lastError = deleteStudent.lastError().text();
			return;
		}
	}

	db.commit();

}

QStringList SchoolDatabasePrivate::studentList() const
{
	QStringList result;

	if (!db.isOpen()) {
		error = true;
		lastError = QObject::tr("Database is not open");
		return result;
	}

	QSqlQuery studentList;

	error = false;

	studentList.prepare("SELECT profile_name FROM students;");
	studentList.exec();

	if (!studentList.isActive()) {
		error = true;
		lastError = studentList.lastError().text();
		return result;
	}

	QSqlRecord studentRec = studentList.record();

	while (studentList.next()) {
		QString profileName = studentList.value(studentRec.indexOf("profile_name")).toString();
		result.append(profileName);
	}
	return result;
}


/************************ SchoolDatabase **************************/

SchoolDatabase::SchoolDatabase(QObject *parent)
		: QObject(parent),
		d_ptr(new SchoolDatabasePrivate())
{
	d_ptr->q_ptr = this;
}

SchoolDatabase::SchoolDatabase(SchoolDatabasePrivate &dd, QObject *parent)
		: QObject(parent),
		d_ptr(&dd)
{
}

SchoolDatabase::~SchoolDatabase()
{
	Q_D(SchoolDatabase);
	delete d;
}

bool SchoolDatabase::open(QString dbFilePath)
{
	Q_D(SchoolDatabase);

	if (d->db.isOpen()) {
		close();
	}

	QFile dbFile(dbFilePath);
	d->db.setDatabaseName(dbFilePath);
	if (dbFile.exists()) {
		return d->db.open();
	} else {
		bool result = d->db.open();
		if (result) {
			d->createTables();
			d->createTriggers();
		}
		return result;
	}
}

void SchoolDatabase::close()
{
	Q_D(SchoolDatabase);
	d->db.close();
}

bool SchoolDatabase::error()
{
	Q_D(SchoolDatabase);
	return d->error;
}

QString SchoolDatabase::lastError()
{
	Q_D(SchoolDatabase);
	return d->lastError;
}

void SchoolDatabase::addClass(Class &newClass)
{
	Q_D(SchoolDatabase);
	d->addClass(newClass);
}

void SchoolDatabase::updateClass(Class &updatedClass)
{
	Q_D(SchoolDatabase);
	d->updateClass(updatedClass);
}

void SchoolDatabase::deleteClass(Class &deletedClass)
{
	Q_D(SchoolDatabase);
	d->deleteClass(deletedClass);
}

void SchoolDatabase::addTeacher(Teacher &newTeacher)
{
	Q_D(SchoolDatabase);
	d->addTeacher(newTeacher);
}

void SchoolDatabase::updateTeacher(Teacher &updatedTeacher)
{
	Q_D(SchoolDatabase);
	d->updateTeacher(updatedTeacher);
}

void SchoolDatabase::deleteTeacher(Teacher &deletedTeacher)
{
	Q_D(SchoolDatabase);
	d->deleteTeacher(deletedTeacher);
}

QList<Class>SchoolDatabase::classList() const
{
	Q_D(const SchoolDatabase);
	return d->classList();
}

QList<Teacher>SchoolDatabase::teacherList() const
{
	Q_D(const SchoolDatabase);
	return d->teacherList();
}

void SchoolDatabase::synchronizeStudents(const QList< QPointer<StudentDir> > &studentList)
{
	Q_D(SchoolDatabase);
	d->synchronizeStudents(studentList);
}

