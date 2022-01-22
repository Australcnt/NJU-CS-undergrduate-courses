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
import com.amaze.filemanager.database.models.explorer.Sort;
import io.reactivex.Completable;
import io.reactivex.Single;
import java.lang.Exception;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.lang.Void;
import java.util.concurrent.Callable;

@SuppressWarnings({"unchecked", "deprecation"})
public final class SortDao_Impl implements SortDao {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<Sort> __insertionAdapterOfSort;

  private final EntityDeletionOrUpdateAdapter<Sort> __updateAdapterOfSort;

  private final SharedSQLiteStatement __preparedStmtOfClear;

  public SortDao_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfSort = new EntityInsertionAdapter<Sort>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR ABORT INTO `sort` (`path`,`type`) VALUES (?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, Sort value) {
        if (value.path == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, value.path);
        }
        stmt.bindLong(2, value.type);
      }
    };
    this.__updateAdapterOfSort = new EntityDeletionOrUpdateAdapter<Sort>(__db) {
      @Override
      public String createQuery() {
        return "UPDATE OR ABORT `sort` SET `path` = ?,`type` = ? WHERE `path` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, Sort value) {
        if (value.path == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, value.path);
        }
        stmt.bindLong(2, value.type);
        if (value.path == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, value.path);
        }
      }
    };
    this.__preparedStmtOfClear = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM sort WHERE path = ?";
        return _query;
      }
    };
  }

  @Override
  public Completable insert(final Sort entity) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __insertionAdapterOfSort.insert(entity);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable update(final Sort entity) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __updateAdapterOfSort.handle(entity);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable clear(final String path) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfClear.acquire();
        int _argIndex = 1;
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
          __preparedStmtOfClear.release(_stmt);
        }
      }
    });
  }

  @Override
  public Single<Sort> find(final String path) {
    final String _sql = "SELECT `sort`.`path` AS `path`, `sort`.`type` AS `type` FROM sort WHERE path = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    if (path == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, path);
    }
    return RxRoom.createSingle(new Callable<Sort>() {
      @Override
      public Sort call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfType = CursorUtil.getColumnIndexOrThrow(_cursor, "type");
          final Sort _result;
          if(_cursor.moveToFirst()) {
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            final int _tmpType;
            _tmpType = _cursor.getInt(_cursorIndexOfType);
            _result = new Sort(_tmpPath,_tmpType);
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
