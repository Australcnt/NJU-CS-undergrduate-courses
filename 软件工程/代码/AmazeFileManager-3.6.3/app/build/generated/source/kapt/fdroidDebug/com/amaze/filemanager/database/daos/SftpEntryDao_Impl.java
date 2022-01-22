package com.amaze.filemanager.database.daos;

import android.database.Cursor;
import androidx.room.EmptyResultSetException;
import androidx.room.EntityDeletionOrUpdateAdapter;
import androidx.room.EntityInsertionAdapter;
import androidx.room.RoomDatabase;
import androidx.room.RoomSQLiteQuery;
import androidx.room.RxRoom;
import androidx.room.SharedSQLiteStatement;
import androidx.room.util.CursorUtil;
import androidx.room.util.DBUtil;
import androidx.sqlite.db.SupportSQLiteStatement;
import com.amaze.filemanager.database.models.utilities.SftpEntry;
import io.reactivex.Completable;
import io.reactivex.Single;
import java.lang.Exception;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.lang.Void;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;

@SuppressWarnings({"unchecked", "deprecation"})
public final class SftpEntryDao_Impl implements SftpEntryDao {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<SftpEntry> __insertionAdapterOfSftpEntry;

  private final EntityDeletionOrUpdateAdapter<SftpEntry> __updateAdapterOfSftpEntry;

  private final SharedSQLiteStatement __preparedStmtOfDeleteByName;

  private final SharedSQLiteStatement __preparedStmtOfDeleteByNameAndPath;

  public SftpEntryDao_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfSftpEntry = new EntityInsertionAdapter<SftpEntry>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR ABORT INTO `sftp` (`_id`,`path`,`name`,`pub_key`,`ssh_key_name`,`ssh_key`) VALUES (nullif(?, 0),?,?,?,?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, SftpEntry value) {
        stmt.bindLong(1, value._id);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
        if (value.name == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, value.name);
        }
        if (value.hostKey == null) {
          stmt.bindNull(4);
        } else {
          stmt.bindString(4, value.hostKey);
        }
        if (value.sshKeyName == null) {
          stmt.bindNull(5);
        } else {
          stmt.bindString(5, value.sshKeyName);
        }
        if (value.sshKey == null) {
          stmt.bindNull(6);
        } else {
          stmt.bindString(6, value.sshKey);
        }
      }
    };
    this.__updateAdapterOfSftpEntry = new EntityDeletionOrUpdateAdapter<SftpEntry>(__db) {
      @Override
      public String createQuery() {
        return "UPDATE OR ABORT `sftp` SET `_id` = ?,`path` = ?,`name` = ?,`pub_key` = ?,`ssh_key_name` = ?,`ssh_key` = ? WHERE `_id` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, SftpEntry value) {
        stmt.bindLong(1, value._id);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
        if (value.name == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, value.name);
        }
        if (value.hostKey == null) {
          stmt.bindNull(4);
        } else {
          stmt.bindString(4, value.hostKey);
        }
        if (value.sshKeyName == null) {
          stmt.bindNull(5);
        } else {
          stmt.bindString(5, value.sshKeyName);
        }
        if (value.sshKey == null) {
          stmt.bindNull(6);
        } else {
          stmt.bindString(6, value.sshKey);
        }
        stmt.bindLong(7, value._id);
      }
    };
    this.__preparedStmtOfDeleteByName = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM sftp WHERE name = ?";
        return _query;
      }
    };
    this.__preparedStmtOfDeleteByNameAndPath = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM sftp WHERE name = ? AND path = ?";
        return _query;
      }
    };
  }

  @Override
  public Completable insert(final SftpEntry instance) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __insertionAdapterOfSftpEntry.insert(instance);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable update(final SftpEntry instance) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __updateAdapterOfSftpEntry.handle(instance);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable deleteByName(final String name) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfDeleteByName.acquire();
        int _argIndex = 1;
        if (name == null) {
          _stmt.bindNull(_argIndex);
        } else {
          _stmt.bindString(_argIndex, name);
        }
        __db.beginTransaction();
        try {
          _stmt.executeUpdateDelete();
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
          __preparedStmtOfDeleteByName.release(_stmt);
        }
      }
    });
  }

  @Override
  public Completable deleteByNameAndPath(final String name, final String path) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfDeleteByNameAndPath.acquire();
        int _argIndex = 1;
        if (name == null) {
          _stmt.bindNull(_argIndex);
        } else {
          _stmt.bindString(_argIndex, name);
        }
        _argIndex = 2;
        if (path == null) {
          _stmt.bindNull(_argIndex);
        } else {
          _stmt.bindString(_argIndex, path);
        }
        __db.beginTransaction();
        try {
          _stmt.executeUpdateDelete();
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
          __preparedStmtOfDeleteByNameAndPath.release(_stmt);
        }
      }
    });
  }

  @Override
  public Single<List<SftpEntry>> list() {
    final String _sql = "SELECT `sftp`.`_id` AS `_id`, `sftp`.`path` AS `path`, `sftp`.`name` AS `name`, `sftp`.`pub_key` AS `pub_key`, `sftp`.`ssh_key_name` AS `ssh_key_name`, `sftp`.`ssh_key` AS `ssh_key` FROM sftp";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    return RxRoom.createSingle(new Callable<List<SftpEntry>>() {
      @Override
      public List<SftpEntry> call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfName = CursorUtil.getColumnIndexOrThrow(_cursor, "name");
          final int _cursorIndexOfHostKey = CursorUtil.getColumnIndexOrThrow(_cursor, "pub_key");
          final int _cursorIndexOfSshKeyName = CursorUtil.getColumnIndexOrThrow(_cursor, "ssh_key_name");
          final int _cursorIndexOfSshKey = CursorUtil.getColumnIndexOrThrow(_cursor, "ssh_key");
          final List<SftpEntry> _result = new ArrayList<SftpEntry>(_cursor.getCount());
          while(_cursor.moveToNext()) {
            final SftpEntry _item;
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            final String _tmpName;
            _tmpName = _cursor.getString(_cursorIndexOfName);
            final String _tmpHostKey;
            _tmpHostKey = _cursor.getString(_cursorIndexOfHostKey);
            final String _tmpSshKeyName;
            _tmpSshKeyName = _cursor.getString(_cursorIndexOfSshKeyName);
            final String _tmpSshKey;
            _tmpSshKey = _cursor.getString(_cursorIndexOfSshKey);
            _item = new SftpEntry(_tmpPath,_tmpName,_tmpHostKey,_tmpSshKeyName,_tmpSshKey);
            _item._id = _cursor.getInt(_cursorIndexOfId);
            _result.add(_item);
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }

  @Override
  public Single<SftpEntry> findByNameAndPath(final String name, final String path) {
    final String _sql = "SELECT `sftp`.`_id` AS `_id`, `sftp`.`path` AS `path`, `sftp`.`name` AS `name`, `sftp`.`pub_key` AS `pub_key`, `sftp`.`ssh_key_name` AS `ssh_key_name`, `sftp`.`ssh_key` AS `ssh_key` FROM sftp WHERE name = ? AND path = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 2);
    int _argIndex = 1;
    if (name == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, name);
    }
    _argIndex = 2;
    if (path == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, path);
    }
    return RxRoom.createSingle(new Callable<SftpEntry>() {
      @Override
      public SftpEntry call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfName = CursorUtil.getColumnIndexOrThrow(_cursor, "name");
          final int _cursorIndexOfHostKey = CursorUtil.getColumnIndexOrThrow(_cursor, "pub_key");
          final int _cursorIndexOfSshKeyName = CursorUtil.getColumnIndexOrThrow(_cursor, "ssh_key_name");
          final int _cursorIndexOfSshKey = CursorUtil.getColumnIndexOrThrow(_cursor, "ssh_key");
          final SftpEntry _result;
          if(_cursor.moveToFirst()) {
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            final String _tmpName;
            _tmpName = _cursor.getString(_cursorIndexOfName);
            final String _tmpHostKey;
            _tmpHostKey = _cursor.getString(_cursorIndexOfHostKey);
            final String _tmpSshKeyName;
            _tmpSshKeyName = _cursor.getString(_cursorIndexOfSshKeyName);
            final String _tmpSshKey;
            _tmpSshKey = _cursor.getString(_cursorIndexOfSshKey);
            _result = new SftpEntry(_tmpPath,_tmpName,_tmpHostKey,_tmpSshKeyName,_tmpSshKey);
            _result._id = _cursor.getInt(_cursorIndexOfId);
          } else {
            _result = null;
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }

  @Override
  public Single<SftpEntry> findByName(final String name) {
    final String _sql = "SELECT `sftp`.`_id` AS `_id`, `sftp`.`path` AS `path`, `sftp`.`name` AS `name`, `sftp`.`pub_key` AS `pub_key`, `sftp`.`ssh_key_name` AS `ssh_key_name`, `sftp`.`ssh_key` AS `ssh_key` FROM sftp WHERE name = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    if (name == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, name);
    }
    return RxRoom.createSingle(new Callable<SftpEntry>() {
      @Override
      public SftpEntry call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfName = CursorUtil.getColumnIndexOrThrow(_cursor, "name");
          final int _cursorIndexOfHostKey = CursorUtil.getColumnIndexOrThrow(_cursor, "pub_key");
          final int _cursorIndexOfSshKeyName = CursorUtil.getColumnIndexOrThrow(_cursor, "ssh_key_name");
          final int _cursorIndexOfSshKey = CursorUtil.getColumnIndexOrThrow(_cursor, "ssh_key");
          final SftpEntry _result;
          if(_cursor.moveToFirst()) {
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            final String _tmpName;
            _tmpName = _cursor.getString(_cursorIndexOfName);
            final String _tmpHostKey;
            _tmpHostKey = _cursor.getString(_cursorIndexOfHostKey);
            final String _tmpSshKeyName;
            _tmpSshKeyName = _cursor.getString(_cursorIndexOfSshKeyName);
            final String _tmpSshKey;
            _tmpSshKey = _cursor.getString(_cursorIndexOfSshKey);
            _result = new SftpEntry(_tmpPath,_tmpName,_tmpHostKey,_tmpSshKeyName,_tmpSshKey);
            _result._id = _cursor.getInt(_cursorIndexOfId);
          } else {
            _result = null;
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }

  @Override
  public Single<String> getSshHostKey(final String uri) {
    final String _sql = "SELECT pub_key FROM sftp WHERE PATH = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    if (uri == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, uri);
    }
    return RxRoom.createSingle(new Callable<String>() {
      @Override
      public String call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final String _result;
          if(_cursor.moveToFirst()) {
            _result = _cursor.getString(0);
          } else {
            _result = null;
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }

  @Override
  public Single<String> getSshAuthPrivateKeyName(final String uri) {
    final String _sql = "SELECT ssh_key_name FROM sftp WHERE PATH = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    if (uri == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, uri);
    }
    return RxRoom.createSingle(new Callable<String>() {
      @Override
      public String call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final String _result;
          if(_cursor.moveToFirst()) {
            _result = _cursor.getString(0);
          } else {
            _result = null;
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }

  @Override
  public Single<String> getSshAuthPrivateKey(final String uri) {
    final String _sql = "SELECT ssh_key FROM sftp WHERE PATH = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    if (uri == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, uri);
    }
    return RxRoom.createSingle(new Callable<String>() {
      @Override
      public String call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final String _result;
          if(_cursor.moveToFirst()) {
            _result = _cursor.getString(0);
          } else {
            _result = null;
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }
}
